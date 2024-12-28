#include "Monomial.h"
#include <vector>
#include <iostream>

class Polynomial
{
private:
    std::vector<Monomial> terms;
    int size;

public:
    Polynomial(const std::vector<std::pair<double, int>> &terms);

    Polynomial(const std::vector<Monomial> &terms);

    void print();
    double evaluate(double value);

    Polynomial derivative();
    Polynomial antiderivative();

    Monomial term(int index);

    double integral(double start, double end);

    friend Polynomial operator+(Polynomial& poly1, Polynomial& poly2);
    // friend Polynomial operator-(const Polynomial& poly1, const Polynomial& poly2);
};