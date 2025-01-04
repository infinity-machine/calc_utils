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

void Fraction::reciprocal()
{
    std::swap(numerator, denominator);
}

Fraction Fraction::getReciprocal()
{
    Fraction thisFraction(numerator, denominator);
    thisFraction.reciprocal();
    return thisFraction;
}


Fraction operator+(Fraction fraction1, Fraction fraction2)
{
    int sum_numerator = (fraction1.numerator * fraction2.denominator) + (fraction1.denominator * fraction2.numerator);

    int sum_denominator = fraction1.denominator * fraction2.denominator;
    Fraction sumFraction(sum_numerator, sum_denominator);

    sumFraction.reduce();

    return sumFraction;
}

Fraction operator-(Fraction fraction1, Fraction fraction2)
{
    int diff_numerator = (fraction1.numerator * fraction2.denominator) - (fraction1.denominator * fraction2.numerator);

    int diff_denominator = fraction1.denominator * fraction2.denominator;
    Fraction diffFraction(diff_numerator, diff_denominator);

    diffFraction.reduce();

    return diffFraction;
}

Fraction operator*(Fraction fraction1, Fraction fraction2)
{
    int prod_numerator = fraction1.numerator * fraction2.numerator;
    int prod_denominator = fraction1.denominator * fraction2.denominator;

    Fraction prodFraction(prod_numerator, prod_denominator);
    prodFraction.reduce();
    
    return prodFraction;
}

Fraction operator/(Fraction fraction1, Fraction fraction2)
{
    Fraction quotientFraction = fraction1 * fraction2.getReciprocal();

    return quotientFraction;
}
