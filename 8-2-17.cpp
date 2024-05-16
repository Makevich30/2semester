#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int binary_to_decimal(const string& binary, int index) {
    if (index < 0) {
        return 0;
    }
    return (binary[index] - '0') * (1 << index) + binary_to_decimal(binary, index - 1);
}

int main() {
    ifstream infile("input.txt");
    ofstream outfile("output.txt");

    string binary;
    infile >> binary;

    int decimal = binary_to_decimal(binary, binary.length() - 1);

    outfile << decimal << endl;

    infile.close();
    outfile.close();

    return 0;
}
