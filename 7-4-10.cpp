#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

int main() {
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");
    int n, sign, result=0;
    
    while(inputFile >> n){
        if (n == '+'){
            sign = 1;
            continue;
        }
        else if (n == '-'){
            sign = -1;
            continue;
        }
        if (sign = -1){
            result += n;
        }
        else result += n;
    }
    outputFile << result;

    inputFile.close();
    outputFile.close();

    return 0;
}
