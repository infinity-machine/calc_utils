#include "../include/Monomial.h"
#include <cmath>
#include <cassert>

Monomial::Monomial(const std::pair<double, int> &coefficients_powers)
{
    assert(coefficients_powers.second >= 0);
    coefficient = coefficients_powers.first;
    power = coefficients_powers.second;
}

double Monomial::coeff()
{
    return coefficient;
}

int Monomial::pwr()
{
    return power;
}

double Monomial::evaluate(double value)
{
    return (this->coeff() * pow(value, this->pwr()));
}

Monomial Monomial::derivative()
{
    int coeff = this->coeff();
    double power = this->pwr();

    double new_coeff = coeff * power;
    int new_power = power - 1;

    Monomial differentiated({new_coeff, new_power});
    return differentiated;
}

Monomial Monomial::antiderivative()
{
    double coeff = this->coeff();
    int power = this->pwr();

    double new_coeff = coeff / (power + 1);
    int new_power = power + 1;

    Monomial antidifferentiated({new_coeff, new_power});
    return antidifferentiated;
}