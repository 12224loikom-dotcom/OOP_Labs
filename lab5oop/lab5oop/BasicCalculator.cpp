#include "BasicCalculator.h"
#include <stdexcept>

double BasicCalculator::add(double a, double b) {
    return a + b;
}

double BasicCalculator::subtract(double a, double b) {
    return a - b;
}

double BasicCalculator::multiply(double a, double b) {
    return a * b;
}

double BasicCalculator::divide(double a, double b) {
    if (b == 0) {
        throw std::invalid_argument("Division by zero!");
    }
    return a / b;
}