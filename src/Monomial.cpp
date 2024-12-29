#include "../include/Monomial.h"
#include <iostream>
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

void Monomial::print()
{
    std::cout << coefficient << "x^" << power; 
}

void Monomial::setCoeff(double coeff)
{
    coefficient = coeff;
}

void Monomial::setPwr(int pwr)
{
    power = pwr;
}

double Monomial::evaluate(double value)
{
    return (this->coeff() * pow(value, this->pwr()));
}

void Monomial::derivative()
{
    double new_coeff = coefficient * power;
    int new_power = power - 1;

    coefficient = new_coeff;
    power = new_power;
}

void Monomial::antiderivative()
{
    double new_coeff = coefficient / (power + 1);
    int new_power = power + 1;

    coefficient = new_coeff;
    power = new_power;
}

double Monomial::integral(double start, double end)
{
    this->antiderivative();
    return (this->evaluate(end) - this->evaluate(start));
}