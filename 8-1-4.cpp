#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int sumOfDigits(int n) {
    int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

void readData(const string& inputFile, int& a, int& b, int& sumValue, int& A) {
    ifstream fin(inputFile);
    if (fin.is_open()) {
        fin >> a >> b >> sumValue >> A;
        fin.close();
    }
}

void writeData(const string& outputFile, const vector<int>& results) {
    ofstream fout(outputFile);
    if (fout.is_open()) {
        for (int result : results) {
            fout << result << endl;
        }
        fout.close();
    }
}

int main() {
    string inputFile = "input.txt";
    string outputFile = "output.txt";

    int a, b, sumValue, A;
    readData(inputFile, a, b, sumValue, A);

    vector<int> results;

    cout << "Сумма цифр для чисел от " << a << " до " << b << ":" << endl;
    for (int i = a; i <= b; ++i) {
        int sum = sumOfDigits(i);
        cout << "Число: " << i << ", Сумма цифр: " << sum << endl;
    }

    cout << "Числа с суммой цифр равной " << sumValue << ":" << endl;
    for (int i = a; i <= b; ++i) {
        if (sumOfDigits(i) == sumValue) {
            cout << i << endl;
            results.push_back(i);
        }
    }

    cout << "Числа с нечетной суммой цифр:" << endl;
    for (int i = a; i <= b; ++i) {
        if (sumOfDigits(i) % 2 != 0) {
            cout << i << endl;
            results.push_back(i);
        }
    }

    int targetSum = sumOfDigits(A);
    int previousNumber = -1;
    for (int i = A - 1; i >= a; --i) {
        if (sumOfDigits(i) == targetSum) {
            previousNumber = i;
            break;
        }
    }
    if (previousNumber != -1) {
        cout << "Предшествующее число для " << A << " с той же суммой цифр: " << previousNumber << endl;
        results.push_back(previousNumber);
    } else {
        cout << "Нет предшествующего числа для " << A << " с той же суммой цифр в заданном диапазоне." << endl;
    }

    writeData(outputFile, results);

    return 0;
}
