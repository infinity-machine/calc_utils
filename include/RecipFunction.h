#pragma once
#include "Monomial.h"
#include "Polynomial.h"

template <class FunctionType>
class ReciprocalFunction
{
private:
    FunctionType inner_function;
    int inner_function_size;
    bool is_composite;

public:
    ReciprocalFunction()
    {
        Monomial init_term({1, 1});
        inner_function = init_term;
    }

    ReciprocalFunction(FunctionType function_instance)
    {
        inner_function = function_instance;
        inner_function_size = function_instance.returnSize();
        std::cout << function_instance.returnSize() << std::endl;
    }

    void print()
    {
        std::cout << "1 / " << inner_function.string() << std::endl;
    }
};