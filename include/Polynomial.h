#include "Function.h"
#include "Monomial.h"
#include <vector>
#include <iostream>

class Polynomial : public Function
{
private:
    std::vector<Monomial> terms;
    int size;

public:
    Polynomial(const std::vector<std::pair<double, int>> &terms);
    Polynomial(const std::vector<Monomial> &terms);

    void orderPwrs();

    void print();
    double evaluate(double value);
    void derivative();
    void antiderivative();
    double integral(double start, double end);

    friend Polynomial operator+(Polynomial& poly1, Polynomial& poly2);
    friend Polynomial operator-(Polynomial& poly1, Polynomial& poly2);

    friend Polynomial operator*(double constant, Polynomial& thisPoly);
    friend Polynomial operator*(Polynomial& poly, double constant);
    friend Polynomial operator*(Monomial& mono, Polynomial& poly);
    friend Polynomial operator*(Polynomial& poly, Monomial& mono);
    // friend Polynomial operator*(Polynomial& poly1, Polynomial& poly2);

    friend Polynomial operator/(Polynomial& poly, double constant);

    // NEED OPERATOR OVERLOADS FOR
    // MULTIPLICATION / BY MONOMIAL
    // MULTIPLICATION / BY POLYNOMIAL
    // = RETURN TRUE / FALSE
    // == TO COPY
};