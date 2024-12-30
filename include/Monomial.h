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
    void setCoeff(double coeff);
    int pwr();
    void setPwr(int pwr);

    void print();
    std::string string();
    double evaluate(double value);
    void differentiate();
    Monomial derivative();
    void antidifferentiate();
    Monomial antiderivative();
    double integral(double start, double end);

    friend Monomial operator*(double constant, Monomial& mono);
    friend Monomial operator*(Monomial& mono, double constant);
    friend Monomial operator*(Monomial& mono1, Monomial& mono2);

    friend Monomial operator/(Monomial& mono, double constant);
};