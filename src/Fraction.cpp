#include "Fraction.h"
#include <string>
#include <iostream>
#include <cmath>
#include <numeric>
#include <cassert>

Fraction::Fraction(double num, double denom)
{
    assert(denom != 0);
    numerator = num;
    denominator = denom;
}

Fraction::Fraction(double decimal)
{
    if (fabs(decimal - 1.0 / 3) < 0.0001)
    {
        numerator = 1;
        denominator = 3;
        return;
    }

    if (fabs(decimal - 2.0 / 3) < 0.0001)
    {
        numerator = 2;
        denominator = 3;
        return;
    }

    int precision = 1000000000;
    denominator = precision;
    numerator = decimal * precision;

    this->reduce();
}

void Fraction::print()
{
    std::cout << numerator << " / " << denominator << std::endl;
}

double Fraction::decimal()
{
    return (double)numerator / (double)denominator;
}

void Fraction::reduce()
{
    int common_factor = std::gcd(numerator, denominator);
    if (common_factor > 1)
    {
        numerator /= common_factor;
        denominator /= common_factor;
    }
}

Fraction operator+(Fraction fraction1, Fraction fraction2)
{
    Fraction sum_fraction(fraction1.decimal() + fraction2.decimal());

    return sum_fraction;
}
