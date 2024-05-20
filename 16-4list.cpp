#include <iostream>
#include <fstream>
#include <list>

using namespace std;

int main() {
    ifstream inputFile("input.txt");

    list<int> originalList;
    int num;

    while (inputFile >> num) {
        originalList.push_back(num);
    }
    inputFile.close();

    list<int> resultList;

    for (int val : originalList) {
        if (val < 0)
            resultList.push_front(val);
        else
            resultList.push_back(val);
    }

    ofstream outputFile("output.txt");
    
    for (int val : resultList) {
        outputFile << val << " ";
    }
    outputFile.close();

    return 0;
}
1 -2 3 -4 5 -6
