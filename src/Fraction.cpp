#include "../include/Fraction.h"
#include <string>
#include <iostream>

void Fraction::print()
{
    std::cout << numerator << " / " << denominator << std::endl;
}

double Fraction::decimal()
{
    return numerator / denominator;
}