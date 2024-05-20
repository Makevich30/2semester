#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include <string>

using namespace std;

bool isPrime(int number) {
    if (number <= 1) return false;
    if (number == 2) return true;
    if (number % 2 == 0) return false;
    for (int i = 3; i <= sqrt(number); i += 2) {
        if (number % i == 0) return false;
    }
    return true;
}

void replacePrimesWithX(vector<char>& vec, char x) {
    string str(vec.begin(), vec.end());
    int start = 0;
    while (start < str.size()) {
        while (start < str.size() && !isdigit(str[start])) {
            start++;
        }
        int end = start;
        while (end < str.size() && isdigit(str[end])) {
            end++;
        }
        if (end - start > 0) {
            int num = stoi(str.substr(start, end - start));
            if (isPrime(num)) {
                fill(vec.begin() + start, vec.begin() + end, x);
            }
        }
        start = end + 1;
    }
}

int main() {
    ifstream inputFile("input.txt");

    char x;
    inputFile >> x;

    string line;
    inputFile >> ws;
    getline(inputFile, line);
    inputFile.close();

    vector<char> digits(line.begin(), line.end());

    replacePrimesWithX(digits, x);

    ofstream outputFile("output.txt");

    for (const char& c : digits) {
        outputFile << c;
    }
    outputFile.close();

    return 0;
}
// 0
// 7 12 9 23 18 5 32 14 11 30 17 6 28 3 21 8 19 16 13 25
