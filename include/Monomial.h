#pragma once
#include "Function.h"
// #include "RecipFunction.h"
#include <vector>

class Monomial : public Function
{
private:
    double coefficient;
    int power;
    int size = 1;

public:
    Monomial();
    Monomial(const std::pair<double, int> &coefficients_powers);

    int returnSize();

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
    // friend ReciprocalFunction operator/(double constant, Monomial& mono);
};