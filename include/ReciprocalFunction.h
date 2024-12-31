#pragma once
#include "Monomial.h"
#include "Polynomial.h"
#include "Fraction.h"
#include <iostream>
#include <numeric>

template <class FunctionType>
class ReciprocalFunction
{
private:
    int numerator;
    FunctionType inner_function;
    int inner_function_size;
    bool is_composite = false;

public:
    ReciprocalFunction()
    {
        Monomial init_term({1, 1});
        numerator = 1;
        inner_function = init_term;
        inner_function_size = 1;
    }

    ReciprocalFunction(FunctionType function_instance)
    {
        numerator = 1;
        inner_function = function_instance;
        inner_function_size = function_instance.returnSize();
        if (inner_function_size > 0)
            is_composite = true;
    }

    ReciprocalFunction(int num, FunctionType function_instance)
    {
        numerator = num;
        inner_function = function_instance;
        inner_function_size = function_instance.returnSize();
        this->reduce();
        if (inner_function_size > 0)
            is_composite = true;
    }

    void print()
    {
        std::cout << numerator << " / " << inner_function.string() << std::endl;
    }

    void reduce()
    {
        // IF DENOMINATOR IS MONOMIAL
        if (inner_function_size == 1)
        {
            // IF COEFFICIENT IS INTEGER
            double coeff = inner_function.coeff();
            if (coeff == static_cast<int>(coeff))
            {
                // CAST COEFFICIENT AS INTEGER
                int coeff_int = static_cast<int>(coeff);
                std::cout << coeff_int << std::endl;
                int common_factor = std::gcd(numerator, coeff_int);
                {
                    // IF GCF EXISTS, REDUCE
                    if (common_factor > 1)
                    {
                        numerator /= common_factor;
                        inner_function.setCoeff(coeff_int / common_factor);
                    }
                }
            }
        }
    }
};