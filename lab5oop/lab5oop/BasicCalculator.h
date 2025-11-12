#ifndef BASIC_CALCULATOR_H
#define BASIC_CALCULATOR_H

#include "Calculator.h"

class BasicCalculator : public Calculator {
public:
    virtual double add(double a, double b) override;
    virtual double subtract(double a, double b) override;
    virtual double multiply(double a, double b) override;
    virtual double divide(double a, double b) override;
};

#endif