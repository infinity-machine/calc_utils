#include "Fraction.h"
#include <string>
#include <iostream>
#include <numeric>

Fraction::Fraction(double num, double denom)
{
    numerator = num;
    denominator = denom;
}

void Fraction::print()
{
    std::cout << numerator << " / " << denominator << std::endl;
}

double Fraction::decimal()
{
    return numerator / denominator;
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

// Fraction operator+(Fraction fraction1, Fraction fraction2){

// }
