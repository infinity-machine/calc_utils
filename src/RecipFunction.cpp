#include "RecipFunction.h"
#include "Monomial.h"
#include <iostream>

ReciprocalFunction::ReciprocalFunction(const std::pair<double, int> &coefficient_power)
{
    coefficient = 1 / coefficient_power.first;
    degree = coefficient_power.second;

    Monomial term({coefficient, degree});
    terms.push_back(term);

}

ReciprocalFunction::ReciprocalFunction(Monomial &mono)
{
    coefficient = 1 / mono.coeff();
    degree = mono.pwr();
    terms.push_back(mono);
}

void ReciprocalFunction::print()
{
    std::cout << "1 / " << "(";
    for(int i = 0; i < terms.size(); i++)
    {
        std::cout << terms[i].string();
    }
    std::cout << ")" << std::endl;
}

// ReciprocalFunction::ReciprocalFunction(const Polynomial poly)
// {

// }