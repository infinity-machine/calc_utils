#include "Function.h"
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

    void derivative();
    void antiderivative();
    void orderPwrs();

    double integral(double start, double end);

    friend Polynomial operator+(Polynomial& poly1, Polynomial& poly2);
    friend Polynomial operator-(Polynomial& poly1, Polynomial& poly2);
};