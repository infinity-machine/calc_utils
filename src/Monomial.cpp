#include "Monomial.h"
#include "unicode.h"
#include <iostream>
#include <cmath>
#include <cassert>
#include <sstream>

Monomial::Monomial()
{
    coefficient = 1;
    power = 1;
}

Monomial::Monomial(const std::pair<double, int> &coefficients_powers)
{
    assert(coefficients_powers.second >= 0);
    coefficient = coefficients_powers.first;
    power = coefficients_powers.second;
}

int Monomial::returnSize()
{
    return size;
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
    if (power >= 10)
        std::cout << "(" << coefficient << "x^" << power << ")";

    if (power < 10 && power > 1)
        std::cout << coefficient << "x" << superscriptDigit(power);

    if (power == 1)
        std::cout << coefficient << "x";

    if (power == 0)
        std::cout << coefficient;
}

std::string Monomial::string()
{
    std::stringstream ss;

    if (power >= 10)
        ss << "(" << coefficient << "x^" << power << ")";

    if (power < 10 && power > 1)
        ss << coefficient << "x" << superscriptDigit(power);

    if (power == 1)
        ss << coefficient << "x";

    if (power == 0)
        ss << coefficient;

    std::string return_string = ss.str();

    return return_string;
}

double Monomial::evaluate(double value)
{
    return (this->coeff() * pow(value, this->pwr()));
}

void Monomial::differentiate()
{
    double new_coeff = coefficient * power;
    int new_power = power - 1;

    coefficient = new_coeff;
    power = new_power;
}

Monomial Monomial::derivative()
{
    double new_coeff = coefficient * power;
    int new_power = power - 1;

    Monomial differentiatedMono({new_coeff, new_power});
    return differentiatedMono;
}

void Monomial::antidifferentiate()
{
    double new_coeff = coefficient / (power + 1);
    int new_power = power + 1;

    coefficient = new_coeff;
    power = new_power;
}

Monomial Monomial::antiderivative()
{
    double new_coeff = coefficient / (power + 1);
    int new_power = power + 1;

    Monomial antidifferentiatedMono({new_coeff, new_power});
    return antidifferentiatedMono;
}

double Monomial::integral(double start, double end)
{
    Monomial antiderivative = this->antiderivative();
    return (antiderivative.evaluate(end) - antiderivative.evaluate(start));
}

Monomial operator*(double constant, Monomial &mono)
{
    double prod_coeff = mono.coefficient * constant;
    Monomial newMono({prod_coeff, mono.power});
    return newMono;
}

Monomial operator*(Monomial &mono, double constant)
{
    double prod_coeff = mono.coefficient * constant;
    Monomial newMono({prod_coeff, mono.power});
    return newMono;
}

Monomial operator*(Monomial &mono1, Monomial &mono2)
{
    double prod_coeff = mono1.coefficient * mono2.coefficient;
    double prod_power = mono1.power + mono2.power;
    Monomial newMono({prod_coeff, prod_power});
    return newMono;
}

Monomial operator/(Monomial &mono, double constant)
{
    double quotient_coeff = mono.coefficient / constant;
    Monomial newMono({quotient_coeff, mono.power});
    return newMono;
}