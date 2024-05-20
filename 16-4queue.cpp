#include <iostream>
#include <fstream>
#include <queue>

using namespace std;

int main() {
    ifstream inputFile("input.txt");

    queue<int> negatives, positives;
    int num;
    while (inputFile >> num) {
        if (num < 0) negatives.push(num);
        else positives.push(num);
    }
    inputFile.close();

    ofstream outputFile("output.txt");
    while (!negatives.empty()) {
        outputFile << negatives.front() << " ";
        negatives.pop();
    }
    while (!positives.empty()) {
        outputFile << positives.front() << " ";
        positives.pop();
    }
    outputFile.close();

    return 0;
}
// 1 -2 3 -4 5 -6
