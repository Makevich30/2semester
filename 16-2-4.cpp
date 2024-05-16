#include <iostream>
#include <fstream>
#include <queue>

using namespace std;

void removeElementsWithLastDigit(queue<int> &q, int x) {
    queue<int> temp;

    while (!q.empty()) {
        int num = q.front();
        q.pop();

        if (num % 10 != x) {
            temp.push(num);
        }
    }

    while (!temp.empty()) {
        q.push(temp.front());
        temp.pop();
    }
}

int main() {
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");

    queue<int> numbers;
    int n;
    int x;

    inputFile >> n;

    for (int i = 0; i < n; ++i) {
        int num;
        inputFile >> num;
        numbers.push(num);
    }

    inputFile >> x;

    removeElementsWithLastDigit(numbers, x);

    while (!numbers.empty()) {
        cout << numbers.front() << " ";
        outputFile << numbers.front() << " ";
        numbers.pop();
    }
    cout << endl;

    inputFile.close();
    outputFile.close();

    return 0;
}
