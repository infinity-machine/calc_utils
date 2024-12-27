#include "Polynomial.h"
#include <cmath>

Polynomial::Polynomial(const std::vector<double> &coefficients)
{
    size = coefficients.size();
    for (int i = 0; i < coefficients.size(); i++)
    {
        double power = size - (1 + i);
        coeff_pwr.push_back({coefficients[i], power});
    }
}

Polynomial::Polynomial(const std::vector<std::pair<double, double>> &coefficients_powers)
{   
    coeff_pwr = coefficients_powers;
    size = coeff_pwr.size();
}

void Polynomial::print()
{
    for (int i = 0; i < size; i++)
    {
        std::cout << "(" << coeff_pwr[i].first << "x^" << coeff_pwr[i].second << ")" << "+" << std::endl;
    }
}

double Polynomial::evaluate(double value)
{
    double sum;
    for(int i = 0; i < size; i++)
    {
        sum = sum + (coeff_pwr[i].first * pow(value, coeff_pwr[i].second));
    }
    return sum;
}
