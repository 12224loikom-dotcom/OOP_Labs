
#ifndef CIRCLE_H
#define CIRCLE_H

#include <iostream>
#include <fstream>
using namespace std;

class Circle {
protected:
    double radius;

public:
    // �����������
    Circle(double r = 1.0) : radius(r) {}

    // ����� ��� ���������� �����
    double getArea() const {
        return 3.14159 * radius * radius;
    }

    // ����� ��� ���������� ������� ����
    double getCircumference() const {
        return 2 * 3.14159 * radius;
    }

    // ����� ��� ������ ����������
    void displayInfo() const {
        cout << "Circle - Radius: " << radius
            << ", Area: " << getArea()
            << ", Circumference: " << getCircumference() << endl;
    }

    // ����� � ����
    void writeToFile(ofstream& file) const {
        file << "Circle - Radius: " << radius
            << ", Area: " << getArea()
            << ", Circumference: " << getCircumference() << endl;
    }
};

#endif