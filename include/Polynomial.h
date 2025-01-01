#pragma once

#include "Function.h"
#include <vector>
#include <iostream>

class Polynomial : public Function
{
private:
    std::vector<std::pair<double, int>> terms;
    int size;
    int degree;

public:
    Polynomial();
    Polynomial(const std::vector<std::pair<double, int>> &terms);

    int returnSize();
    double coeffAt(int index);
    void setCoeffAt(double coeff, int index);
    int pwrAt(int index);
    void setPwrAt(int pwr, int index);
    void addTerm(std::pair<double, int>);

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

    // friend Polynomial operator*(double constant, Polynomial& thisPoly);
    // friend Polynomial operator*(Polynomial& poly, double constant);
    // // friend Polynomial operator*(Polynomial& poly1, Polynomial& poly2);
    // friend Polynomial operator/(Polynomial& poly, double constant);
};