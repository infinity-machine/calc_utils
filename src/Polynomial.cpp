#include "Polynomial.h"
#include "Monomial.h"
#include "unicode.h"
#include <cmath>
#include <algorithm>
#include <sstream>

// CONSTRUCTOR GIVEN COEFFICIENTS AND RESPECTIVE POWERS
Polynomial::Polynomial(const std::vector<std::pair<double, int>> &monomial_terms)
{
    for (int i = 0; i < monomial_terms.size(); i++)
    {
        Monomial term(monomial_terms[i]);
        terms.push_back(term);
    }

    size = terms.size();
}

// CONSTRUCTOR GIVEN VECTOR OF MONOMIAL CLASS INSTANCES
Polynomial::Polynomial(const std::vector<Monomial> &monomial_terms)
{
    terms = monomial_terms;
    size = monomial_terms.size();
}

// ORGANIZE BY DESCENDING ORDER OF TERM POWERS
void Polynomial::orderPwrs()
{
    std::sort(terms.begin(), terms.end(), [](auto &left, auto &right)
              { return left.pwr() > right.pwr(); });
}

// PRINT POLYNOMIAL
void Polynomial::print()
{
    for (int i = 0; i < size; i++)
    {
        std::cout << terms[i].string();

        if ((i + 1) != size)
            std::cout << " + ";
    }
}

std::string Polynomial::string()
{
    std::stringstream ss;

    for (int i = 0; i < size; i++)
    {
        ss << terms[i].string();

        if ((i + 1) != size)
            ss << " + ";
    }

    std::string return_string = ss.str();

    return return_string;
}

// EVALUATE POLYNOMIAL FOR GIVEN VALUE
double Polynomial::evaluate(double value)
{
    double sum = 0;

    for (int i = 0; i < size; i++)
    {
        sum = sum + (terms[i].evaluate(value));
    }

    return sum;
}

// DIFFERENTIATE POLYNOMIAL
void Polynomial::differentiate()
{
    for (int i = 0; i < size; i++)
    {
        if (terms[i].pwr() != 0)
            terms[i].differentiate();

        else
        {
            terms.erase(terms.begin() + i);
            size--;
        }
    }
}

// RETURN DIFFERENTIATED POLYNOMIAL
Polynomial Polynomial::derivative()
{
    std::vector<Monomial> differentiatedTerms;

    for (int i = 0; i < size; i++)
    {
        if (terms[i].pwr() != 0)
            differentiatedTerms.push_back(terms[i].derivative());

        else
        {
            terms.erase(terms.begin() + i);
            size--;
        }
    }

    Polynomial differentiatedPoly(differentiatedTerms);
    return differentiatedPoly;
}

// ANTIDIFFERENTIATE POLYNOMIAL
void Polynomial::antidifferentiate()
{
    for (int i = 0; i < size; i++)
    {
        terms[i].antidifferentiate();
    }
}

// RETURN ANTIDIFFERENTIATED POLYNOMIAL
Polynomial Polynomial::antiderivative()
{
    std::vector<Monomial> antidifferentiatedTerms;
    for (int i = 0; i < size; i++)
    {
        if (terms[i].pwr() != 0)
            antidifferentiatedTerms.push_back(terms[i].antiderivative());

        else
        {
            terms.erase(terms.begin() + i);
            size--;
        }
    }

    Polynomial antidifferentiatedPoly(antidifferentiatedTerms);
    return antidifferentiatedPoly;
}

// RETURN INTEGRAL FROM B TO A
double Polynomial::integral(double start, double end)
{
    for (int i = 0; i < size; i++)
    {
        terms[i].antidifferentiate();
    }

    return (this->evaluate(end) - this->evaluate(start));
}

// POLYNOMIAL ADDITION
Polynomial operator+(Polynomial &poly1, Polynomial &poly2)
{
    std::vector<Monomial> new_terms;

    int i = 0, j = 0;

    while (i < poly1.size && j < poly2.size)
    {
        if (poly1.terms[i].pwr() == poly2.terms[j].pwr())
        {
            double coeff_sum = poly1.terms[i].coeff() + poly2.terms[j].coeff();

            if (coeff_sum != 0)
            {
                Monomial newTerm({coeff_sum, poly1.terms[i].pwr()});
                new_terms.push_back(newTerm);
            }
            i++;
            j++;
        }

        else if (poly1.terms[i].pwr() > poly2.terms[j].pwr())
        {
            new_terms.push_back(poly1.terms[i]);
            i++;
        }

        else
        {
            new_terms.push_back(poly2.terms[j]);
            j++;
        }
    }

    while (i < poly1.size)
    {
        new_terms.push_back(poly1.terms[i]);
        i++;
    }

    while (j < poly2.size)
    {
        new_terms.push_back(poly2.terms[j]);
        j++;
    }

    Polynomial newPolynomial(new_terms);
    return newPolynomial;
}

// // POLYNOMIAL SUBTRACTION
Polynomial operator-(Polynomial &poly1, Polynomial &poly2)
{
    std::vector<Monomial> new_terms;

    int i = 0, j = 0;

    while (i < poly1.size && j < poly2.size)
    {
        if (poly1.terms[i].pwr() == poly2.terms[j].pwr())
        {
            double coeff_diff = poly1.terms[i].coeff() - poly2.terms[j].coeff();

            if (coeff_diff != 0)
            {
                Monomial newTerm({coeff_diff, poly1.terms[i].pwr()});
                new_terms.push_back(newTerm);
            }
            i++;
            j++;
        }

        else if (poly1.terms[i].pwr() > poly2.terms[j].pwr())
        {
            new_terms.push_back(poly1.terms[i]);
            i++;
        }

        else
        {
            Monomial negTerm({-poly2.terms[j].coeff(), poly2.terms[j].pwr()});
            new_terms.push_back(negTerm);
            j++;
        }
    }

    while (i < poly1.size)
    {
        new_terms.push_back(poly1.terms[i]);
        i++;
    }

    while (j < poly2.size)
    {
        Monomial negTerm({-poly2.terms[j].coeff(), poly2.terms[j].pwr()});
        new_terms.push_back(negTerm);
        j++;
    }

    Polynomial newPolynomial(new_terms);
    return newPolynomial;
}

Polynomial operator*(double constant, Polynomial &poly)
{
    std::vector<Monomial> prod_terms;

    for (int i = 0; i < poly.size; i++)
    {
        prod_terms.push_back(constant * poly.terms[i]);
    }

    Polynomial prodPoly(prod_terms);
    return prodPoly;
}

Polynomial operator*(Polynomial &poly, double constant)
{
    std::vector<Monomial> prod_terms;

    for (int i = 0; i < poly.size; i++)
    {
        prod_terms.push_back(constant * poly.terms[i]);
    }

    Polynomial prodPoly(prod_terms);
    return prodPoly;
}

Polynomial operator*(Monomial &mono, Polynomial &poly)
{
    std::vector<Monomial> prod_terms;

    for (int i = 0; i < poly.size; i++)
    {
        prod_terms.push_back(mono * poly.terms[i]);
    }

    Polynomial prodPoly(prod_terms);
    return prodPoly;
}

Polynomial operator*(Polynomial &poly, Monomial &mono)
{
    std::vector<Monomial> prod_terms;

    for (int i = 0; i < poly.size; i++)
    {
        prod_terms.push_back(mono * poly.terms[i]);
    }

    Polynomial prodPoly(prod_terms);
    return prodPoly;
}

// Polynomial operator*(Polynomial& poly1, Polynomial& poly2)
// {
//     std::vector<Monomial> prod_terms;

// }

Polynomial operator/(Polynomial &poly, double constant)
{
    std::vector<Monomial> quotient_terms;

    for (int i = 0; i < poly.size; i++)
    {
        quotient_terms.push_back(poly.terms[i] / constant);
    }
    
    Polynomial prodPoly(quotient_terms);
    return prodPoly;
}