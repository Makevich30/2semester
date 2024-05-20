#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void insertBeforeEven(vector<int>& sequence, int x) {
    for (int i = 0; i < sequence.size(); i++) {
        if (sequence[i] % 2 == 0) {
            sequence.insert(sequence.begin() + i, x);
            i++;
        }
    }
}

int main() {
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");

    int x;
    inputFile >> x;

    vector<int> sequence;
    int num;
    while (inputFile >> num) {
        sequence.push_back(num);
    }

    inputFile.close();

    insertBeforeEven(sequence, x);

    for (int num : sequence) {
        outputFile << num << " ";
    }
    outputFile << endl;

    outputFile.close();

    return 0;
}
// 0
// 7 12 9 23 18 5 32 14 11 30 17 6 28 3 21 8 19 16 13 25
