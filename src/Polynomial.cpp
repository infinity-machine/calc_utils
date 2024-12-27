#include "Polynomial.h"
#include <cassert>
#include <cmath>

Polynomial::Polynomial(const std::vector<double> &coefficients)
{
    coeffs = coefficients;
    size = coefficients.size();
    for (double i = (size - 1); i >= 0; i--)
    {
        pwrs.push_back(i);
    }
}

Polynomial::Polynomial(const std::vector<double> &coefficients, const std::vector<double> &powers)
{
    assert(coefficients.size() == powers.size());
    coeffs = coefficients;
    pwrs = powers;
    size = coefficients.size();
}

void Polynomial::print()
{
    for (int i = 0; i < size; i++)
    {
        std::cout << "(" << coeffs[i] << "x^" << pwrs[i] << ")" << "+" << std::endl;
    }
}

double Polynomial::evaluate(double value)
{
    double sum;
    for(int i = 0; i < size; i++)
    {
        sum = sum + (coeffs[i] * pow(value, pwrs[i]));
    }
    return sum;
}
