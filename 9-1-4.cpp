#include <iostream>
#include <fstream>
#include <string>
#include <limits>

using namespace std;

int main() {
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");

    string shortestString;
    string currentString;
    int shortestLength = numeric_limits<int>::max();

    while (getline(inputFile, currentString)) {
        if (currentString.length() < shortestLength) {
            shortestString = currentString;
            shortestLength = currentString.length();
        }
    }

    if (shortestLength != numeric_limits<int>::max()) {
        outputFile << "Shortest string: " << shortestString << endl;
        outputFile << "Length: " << shortestLength << endl;
    } else

    inputFile.close();
    outputFile.close();

    return 0;
}
// This is a test.
// Short string.
// Another string.
