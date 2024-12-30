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

void Monomial::setCoeff(double coeff)
{
    coefficient = coeff;
}

int Monomial::pwr()
{
    return power;
}

void Monomial::setPwr(int pwr)
{
    power = pwr;
}

void Monomial::print()
{
    std::cout << coefficient << "x^" << power;
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

Monomial operator*(double constant, Monomial& mono)
{      
    double prod_coeff = mono.coefficient * constant;
    Monomial newMono({prod_coeff, mono.power});
    return newMono;
}

Monomial operator*(Monomial& mono, double constant)
{
    double prod_coeff = mono.coefficient * constant;
    Monomial newMono({prod_coeff, mono.power});
    return newMono;
}

Monomial operator*(Monomial&mono1, Monomial&mono2)
{
    double prod_coeff = mono1.coefficient * mono2.coefficient;
    double prod_power = mono1.power + mono2.power;
    Monomial newMono({prod_coeff, prod_power});
    return newMono;
}

Monomial operator/(Monomial& mono, double constant)
{
    double quotient_coeff = mono.coefficient / constant;
    Monomial newMono({quotient_coeff, mono.power});
    return newMono;
}