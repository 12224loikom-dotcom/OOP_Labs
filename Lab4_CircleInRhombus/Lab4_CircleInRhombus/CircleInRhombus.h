#ifndef CIRCLEINRHOMBUS_H
#define CIRCLEINRHOMBUS_H

#include "Circle.h"
#include "Rhombus.h"

class CircleInRhombus : public Circle, public Rhombus {
public:
    // Конструктор
    CircleInRhombus(double d1 = 4.0, double d2 = 4.0) : Rhombus(d1, d2) {
        // Обчислюємо радіус вписаного кола: r = (d1*d2) / (2*√(d1²+d2²))
        radius = (d1 * d2) / (2 * sqrt(d1 * d1 + d2 * d2));
    }

    // Метод для виводу інформації
    void displayInfo() const {
        cout << "Circle in Rhombus:" << endl;
        cout << "  Rhombus - Diagonals: " << diagonal1 << ", " << diagonal2
            << ", Area: " << Rhombus::getArea() << endl;
        cout << "  Circle - Radius: " << radius
            << ", Area: " << Circle::getArea()
            << ", Circumference: " << getCircumference() << endl;
    }

    // Запис у файл
    void writeToFile(ofstream& file) const {
        file << "Circle in Rhombus:" << endl;
        file << "  Rhombus - Diagonals: " << diagonal1 << ", " << diagonal2
            << ", Area: " << Rhombus::getArea() << endl;
        file << "  Circle - Radius: " << radius
            << ", Area: " << Circle::getArea()
            << ", Circumference: " << getCircumference() << endl;
    }
};

#endif