#include "../include/Monomial.h"

Monomial::Monomial(const std::pair<double, int> &coefficients_powers)
{
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