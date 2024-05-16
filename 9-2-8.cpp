#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream file1("file1.txt");
    ifstream file2("file2.txt");
    ofstream outputFile("output.txt");

    int number;

    while (file1 >> number) {
        if (number % 2 == 0) {
            outputFile << number << endl;
        }
    }

    while (file2 >> number) {
        if (number % 2 != 0) {
            outputFile << number << endl;
        }
    }

    file1.close();
    file2.close();
    outputFile.close();

    return 0;
}
