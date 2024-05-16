#include <iostream>
#include <fstream>
#include <stack>
#include <vector>

using namespace std;

void replaceElements(vector<int>& sequence, int x, int y) {
    stack<int> stack;

    for (int num : sequence) {
        if (num != x) {
            stack.push(num);
        }
    }

    while (!stack.empty()) {
        sequence[stack.size() - 1] = stack.top();
        stack.pop();
    }

    if (!sequence.empty() && sequence.back() == x) {
        sequence.back() = y;
    }
}

int main() {
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");

    vector<int> sequence;
    int x, y, num;

    while (inputFile >> num) {
        sequence.push_back(num);
    }
    inputFile >> x >> y;
    
    replaceElements(sequence, x, y);

    for (int num : sequence) {
        outputFile << num << " ";
    }
    outputFile << endl;

    inputFile.close();
    outputFile.close();

    return 0;
}
// 2 3 4 5 2 7 2
// 2 8
