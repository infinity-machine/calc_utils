#include "LogFunction.h"
#include "unicode.h"
#include <iostream>

LogFunction::LogFunction(int log_base)
{
    base = log_base;
}

void LogFunction::print()
{
    std::cout << "log" << subscriptDigit(base) << "x" << std::endl; 
}

double LogFunction::evaluate(double value)
{
    if (base == 2)
        return log2(value);

    if (base == 10)
        return log10(value);

    else return log(value) / log(base);
    
}