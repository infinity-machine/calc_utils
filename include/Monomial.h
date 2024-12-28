#pragma once
#include <vector>

class Monomial
{
private:
    double coefficient;
    int power;

public:
    Monomial(const std::pair<double, int> &coefficients_powers);

    double coeff();
    int pwr();

    double evaluate(double value);

    Monomial derivative();
    Monomial antiderivative();
};