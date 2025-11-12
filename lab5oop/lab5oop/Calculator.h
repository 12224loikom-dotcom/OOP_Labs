#ifndef CALCULATOR_H
#define CALCULATOR_H

class Calculator {
public:
    virtual double add(double a, double b) = 0;
    virtual double subtract(double a, double b) = 0;
    virtual double multiply(double a, double b) = 0;
    virtual double divide(double a, double b) = 0;
    virtual ~Calculator() {}
};

#endif