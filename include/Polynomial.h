#include <vector>
#include <iostream>

class Polynomial
{
private:
    std::vector<double> coeffs;
    std::vector<double> pwrs;
    int size;

public:
    Polynomial(const std::vector<double> &coefficients);
    Polynomial(const std::vector<double> &coefficients, const std::vector<double> &powers);

    void print();

    double evaluate(double value);
};