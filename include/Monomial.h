#pragma once
#include "Function.h"
#include <vector>

class Monomial : public Function
{
private:
    double coefficient;
    int power;

public:
    Monomial(const std::pair<double, int> &coefficients_powers);

    double coeff();
    int pwr();

    void print();

    void setCoeff(double coeff);
    void setPwr(int pwr);

    double evaluate(double value);

    void derivative();
    void antiderivative();
    double integral(double start, double end);
};