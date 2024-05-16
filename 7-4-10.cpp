#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

// Функция для вычисления результата выражения
double calculateExpression(const string& expression) {
    istringstream iss(expression);
    double operand1, operand2;
    char operation;
    iss >> operand1 >> operation >> operand2;

    switch (operation) {
        case '+':
            return operand1 + operand2;
        case '-':
            return operand1 - operand2;
    }
}

int main() {
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");
    string expression;
    getline(inputFile, expression);

    double result = calculateExpression(expression);

    outputFile << "Решение примера: " << result << endl;

    inputFile.close();
    outputFile.close();

    return 0;
}
