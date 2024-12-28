#include "Monomial.h"
#include <vector>
#include <iostream>

class Polynomial
{
private:
    std::vector<Monomial> terms;
    int size;

public:
    Polynomial(const std::vector<std::pair<double, double>> &coefficients_powers);

    void print();
    double evaluate(double value);

    Polynomial derivative();
    Polynomial antiderivative();

    double integral(double start, double end);

    // friend Polynomial operator+(const Polynomial& poly1, const Polynomial& poly2);
    // friend Polynomial operator-(const Polynomial& poly1, const Polynomial& poly2);
};