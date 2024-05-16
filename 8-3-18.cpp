#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void replaceNegative(vector<int>& arr, int index = 0) {
    if (index == arr.size())
        return;

    if (arr[index] < 0)
        arr[index] *= -1;

    replaceNegative(arr, index + 1);
}

int main() {
    vector<int> arr;

    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");
    
    int num;
    while (inputFile >> num) {
        arr.push_back(num);
    }

    replaceNegative(arr);

    for (int i = 0; i < arr.size(); ++i) {
        outputFile << arr[i] << " ";
    }
    
    inputFile.close();
    outputFile.close();

    return 0;
}
// -1 2 -3 4 -5
