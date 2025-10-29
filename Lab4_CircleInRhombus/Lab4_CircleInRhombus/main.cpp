
#include <iostream>
#include <fstream>
#include "CircleInRhombus.h"

using namespace std;

int main() {
    cout << "=== Laboratory Work 4 ===" << endl;
    cout << "=== Circle in Rhombus ===" << endl << endl;

    // Комплект 1 вхідних даних
    cout << "=== SET 1 ===" << endl;
    Circle circle1(3.0);
    Rhombus rhombus1(8.0, 6.0);
    CircleInRhombus cir1(8.0, 6.0);

    circle1.displayInfo();
    rhombus1.displayInfo();
    cir1.displayInfo();

    // Комплект 2 вхідних даних
    cout << "\n=== SET 2 ===" << endl;
    Circle circle2(2.0);
    Rhombus rhombus2(10.0, 5.0);
    CircleInRhombus cir2(10.0, 5.0);

    circle2.displayInfo();
    rhombus2.displayInfo();
    cir2.displayInfo();

    // Вивід інформації у файл
    cout << "\n=== FILE OUTPUT ===" << endl;
    ofstream file("geometry_data.txt");

    if (file.is_open()) {
        file << "=== CLASS INFORMATION ===" << endl << endl;

        file << "=== Set 1 ===" << endl;
        cir1.writeToFile(file);
        file << endl;

        file << "=== Set 2 ===" << endl;
        cir2.writeToFile(file);

        file.close();
        cout << "Information written to file 'geometry_data.txt'" << endl;
    }
    else {
        cout << "Error opening file!" << endl;
    }

    cout << "\nPress Enter to exit...";
    cin.get();

    return 0;
}