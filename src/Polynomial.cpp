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
        std::cout << "(" << coeff_pwr[i].first << "x^" << coeff_pwr[i].second << ")";
        if((i + 1) != size) std::cout << " + ";
    }
    std::cout << "\n";
}

double Polynomial::evaluate(double value)
{
    double sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum = sum + (coeff_pwr[i].first * pow(value, coeff_pwr[i].second));
    }
    return sum;
}

Polynomial Polynomial::derivative()
{
    std::vector<std::pair<double, double>> differentiated_coeff_pwr;
    for (int i = 0; i < size; i++)
    {
        if (coeff_pwr[i].second != 0)
        {
            double coeff = (coeff_pwr[i].first * coeff_pwr[i].second);
            double pwr = (coeff_pwr[i].second - 1);

            differentiated_coeff_pwr.push_back(std::make_pair(coeff, pwr));
        }
    }
    Polynomial differentiatedPolynomial(differentiated_coeff_pwr);
    return differentiatedPolynomial;
}

Polynomial Polynomial::antiderivative()
{
    std::vector<std::pair<double, double>> antidifferentiated_coeff_pwr;
    for (int i = 0; i < size; i++)
    {
        double coeff = (coeff_pwr[i].first / (coeff_pwr[i].second + 1));
        double pwr = (coeff_pwr[i].second + 1);

        antidifferentiated_coeff_pwr.push_back(std::make_pair(coeff, pwr));
    }
    Polynomial antidifferentiatedPolynomial(antidifferentiated_coeff_pwr);
    return antidifferentiatedPolynomial;
}

double Polynomial::integral(double start, double end)
{
    Polynomial antideriv = this->antiderivative();
    return (antideriv.evaluate(end) - antideriv.evaluate(start));
}
