#include <iostream>
#include "BasicCalculator.h"

using namespace std;

int main() {
    Calculator* calc = new BasicCalculator();

    double x = 10.0, y = 5.0;

    cout << "x = " << x << ", y = " << y << endl;
    cout << "Addition: " << calc->add(x, y) << endl;
    cout << "Subtraction: " << calc->subtract(x, y) << endl;
    cout << "Multiplication: " << calc->multiply(x, y) << endl;

    try 
    {
        cout << "Division: " << calc->divide(x, y) << endl;
        cout << "Division by zero: " << calc->divide(x, 0) << endl;
    }
    catch (const exception& e) 
    {
        cout << "Error: " << e.what() << endl;
    }

    delete calc;
    return 0;
}