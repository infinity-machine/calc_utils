#include "Trinomial.h"
#include <cmath>
#include <iostream>

Trinomial::Trinomial(double a, double b, double c)
{
    coeff_a = a;
    coeff_b = b;
    coeff_c = c;
}

double Trinomial::evaluate(double value)
{
    return (coeff_a * pow((value), 2)) + (coeff_b * value) + coeff_c;
}

double Trinomial::discriminant()
{
    return pow(coeff_b, 2) - (4 * coeff_a * coeff_c);
}

void Trinomial::roots()
{
    float discriminant = this->discriminant();

    if (discriminant < 0)
        std::cout << "NO REAL ROOTS" << std::endl;

    if (discriminant == 0)
    {
        double x = -coeff_b / (2 * coeff_a);
        std::cout << "ONE REAL ROOT:\n"
                  << x << std::endl;
    }

    if (discriminant > 0)
    {
        double x1 = (-coeff_b - sqrt(discriminant)) / (2 * coeff_a);
        double x2 = (-coeff_b + sqrt(discriminant)) / (2 * coeff_a);

        std::cout << "TWO REAL ROOTS\n"
             << x1 << "\n"
             << x2 << std::endl;
    }
}
