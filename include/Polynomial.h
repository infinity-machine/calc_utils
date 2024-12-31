#pragma once

#include "Function.h"
#include "Monomial.h"
#include <vector>
#include <iostream>

class Polynomial : public Function
{
private:
    std::vector<Monomial> terms;
    int size;
    int degree;

public:
    Polynomial();
    Polynomial(const std::vector<std::pair<double, int>> &terms);
    Polynomial(const std::vector<Monomial> &terms);

    int returnSize();

    void addTerm(Monomial term);

    void orderPwrs();

    void print();
    std::string string();

    double evaluate(double value);
    void differentiate();
    Polynomial derivative();
    void antidifferentiate();
    Polynomial antiderivative();
    double integral(double start, double end);

    friend Polynomial operator+(Polynomial& poly1, Polynomial& poly2);
    friend Polynomial operator-(Polynomial& poly1, Polynomial& poly2);

    friend Polynomial operator*(double constant, Polynomial& thisPoly);
    friend Polynomial operator*(Polynomial& poly, double constant);
    friend Polynomial operator*(Monomial& mono, Polynomial& poly);
    friend Polynomial operator*(Polynomial& poly, Monomial& mono);
    // friend Polynomial operator*(Polynomial& poly1, Polynomial& poly2);

    friend Polynomial operator/(Polynomial& poly, double constant);

    // void operator=(std::vector<Monomial> mono_vector)
    // {

    // }

    // NEED OPERATOR OVERLOADS FOR
    // MULTIPLICATION / BY MONOMIAL
    // MULTIPLICATION / BY POLYNOMIAL
    // = RETURN TRUE / FALSE
    // == TO COPY
};