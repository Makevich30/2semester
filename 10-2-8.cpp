#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Car {
    string brand;
    string number;
    string ownerLastName;
    int purchaseYear;
    int mileage;
};

// Функция для чтения данных из файла
void readDataFromFile(const string& filename, Car cars[], int& numCars) {
    ifstream inputFile(filename);
    if (!inputFile.is_open()) {
        cerr << "Unable to open input file" << endl;
        exit(1);
    }

    inputFile >> numCars;
    for (int i = 0; i < numCars; ++i) {
        inputFile >> cars[i].brand >> cars[i].number >> cars[i].ownerLastName >> cars[i].purchaseYear >> cars[i].mileage;
    }

    inputFile.close();
}

// Функция для записи данных в файл
void writeDataToFile(const string& filename, const Car cars[], int numCars) {
    ofstream outputFile(filename);
    if (!outputFile.is_open()) {
        cerr << "Unable to open output file" << endl;
        exit(1);
    }

    outputFile << numCars << endl;
    for (int i = 0; i < numCars; ++i) {
        outputFile << cars[i].brand << " " << cars[i].number << " " << cars[i].ownerLastName << " " << cars[i].purchaseYear << " " << cars[i].mileage << endl;
    }

    outputFile.close();
}

// Функция для удаления автомобилей с пробегом менее заданного значения
void removeCarsWithLessMileage(Car cars[], int& numCars, int minMileage) {
    int j = 0;
    for (int i = 0; i < numCars; ++i) {
        if (cars[i].mileage >= minMileage) {
            cars[j] = cars[i];
            ++j;
        }
    }
    numCars = j;
}

int main() {
    const string inputFile = "input.txt"; // Имя входного файла
    const string outputFile = "output.txt"; // Имя выходного файла
    const int minMileage = 100000; // Минимальный пробег для включения в автомобильную ведомость

    const int MAX_CARS = 1000; // Максимальное количество автомобилей
    Car cars[MAX_CARS];
    int numCars;

    // Чтение данных из файла
    readDataFromFile(inputFile, cars, numCars);

    // Удаление автомобилей с пробегом менее заданного значения
    removeCarsWithLessMileage(cars, numCars, minMileage);

    // Запись данных в файл
    writeDataToFile(outputFile, cars, numCars);

    cout << "Automobile register created successfully!" << endl;

    return 0;
}
// 5
// Toyota ABC123 Ivanov 2018 90000
// Honda XYZ789 Petrov 2019 110000
// Ford DEF456 Sidorov 2017 80000
// Chevrolet GHI789 Smirnov 2020 95000
// Nissan JKL012 Kuznetsov 2016 120000
