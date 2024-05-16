#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int sum_digits(int n) {
    int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

void print_sums(ifstream& infile, ofstream& outfile) {
    int a, b;
    infile >> a >> b;
    for (int i = a; i <= b; i++) {
        outfile << i << ": " << sum_digits(i) << endl;
    }
}

void print_numbers_with_sum(ifstream& infile, ofstream& outfile) {
    int a, b, sum;
    infile >> a >> b >> sum;
    for (int i = a; i <= b; i++) {
        if (sum_digits(i) == sum) {
            outfile << i << endl;
        }
    }
}

void print_numbers_with_odd_sum(ifstream& infile, ofstream& outfile) {
    int a, b;
    infile >> a >> b;
    for (int i = a; i <= b; i++) {
        if (sum_digits(i) % 2 == 1) {
            outfile << i << endl;
        }
    }
}

void print_prev_number_with_same_sum(ifstream& infile, ofstream& outfile) {
    int a;
    infile >> a;
    int sum = sum_digits(a);
    int prev_sum = sum + 1;
    while (prev_sum != sum) {
        a--;
        prev_sum = sum_digits(a);
    }
    outfile << a << endl;
}

int main() {
    ifstream infile("input.txt");
    ofstream outfile("output.txt");

    print_sums(infile, outfile);
    outfile << endl;

    print_numbers_with_sum(infile, outfile);
    outfile << endl;

    print_numbers_with_odd_sum(infile, outfile);
    outfile << endl;

    print_prev_number_with_same_sum(infile, outfile);

    infile.close();
    outfile.close();

    return 0;
}
