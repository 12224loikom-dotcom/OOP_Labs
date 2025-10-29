#ifndef RHOMBUS_H
#define RHOMBUS_H

#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

class Rhombus {
protected:
    double diagonal1, diagonal2;

public:
    // Конструктор
    Rhombus(double d1 = 1.0, double d2 = 1.0) : diagonal1(d1), diagonal2(d2) {}

    // Метод для обчислення площі
    double getArea() const {
        return (diagonal1 * diagonal2) / 2.0;
    }

    // Метод для виводу інформації
    void displayInfo() const {
        cout << "Rhombus - Diagonal1: " << diagonal1
            << ", Diagonal2: " << diagonal2
            << ", Area: " << getArea() << endl;
    }

    // Запис у файл
    void writeToFile(ofstream& file) const {
        file << "Rhombus - Diagonal1: " << diagonal1
            << ", Diagonal2: " << diagonal2
            << ", Area: " << getArea() << endl;
    }
};

#endif