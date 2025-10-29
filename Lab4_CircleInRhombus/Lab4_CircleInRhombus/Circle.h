
#ifndef CIRCLE_H
#define CIRCLE_H

#include <iostream>
#include <fstream>
using namespace std;

class Circle {
protected:
    double radius;

public:
    // Конструктор
    Circle(double r = 1.0) : radius(r) {}

    // Метод для обчислення площі
    double getArea() const {
        return 3.14159 * radius * radius;
    }

    // Метод для обчислення довжини кола
    double getCircumference() const {
        return 2 * 3.14159 * radius;
    }

    // Метод для виводу інформації
    void displayInfo() const {
        cout << "Circle - Radius: " << radius
            << ", Area: " << getArea()
            << ", Circumference: " << getCircumference() << endl;
    }

    // Запис у файл
    void writeToFile(ofstream& file) const {
        file << "Circle - Radius: " << radius
            << ", Area: " << getArea()
            << ", Circumference: " << getCircumference() << endl;
    }
};

#endif