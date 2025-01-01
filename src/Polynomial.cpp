#include "Polynomial.h"
#include "unicode.h"
#include <cmath>
#include <algorithm>
#include <sstream>

Polynomial::Polynomial()
{
    size = 1;
    degree = 1;

    std::pair<double, int> term;

    term = std::make_pair(1, 1);
    terms.push_back(term);
}

// CONSTRUCTOR GIVEN COEFFICIENTS AND RESPECTIVE POWERS
Polynomial::Polynomial(const std::vector<std::pair<double, int>> &monomials)
{
    for (int i = 0; i < monomials.size(); i++)
    {
        terms.push_back(monomials[i]);
    }

    size = monomials.size();
    // DEGREE = POWER OF LARGEST MONOMIAL TERM
}

int Polynomial::returnSize()
{
    return size;
}

void Polynomial::addTerm(std::pair<double, int> monomial)
{
    terms.push_back(monomial);
    size++;
    degree = monomial.second;
    this->orderPwrs();
}

// ORGANIZE BY DESCENDING ORDER OF TERM POWERS
void Polynomial::orderPwrs()
{
    std::sort(terms.begin(), terms.end(), [](auto &left, auto &right)
              { return left.second > right.second; });
}

// PRINT POLYNOMIAL
void Polynomial::print()
{
    std::cout << this->string() << std::endl;
}

std::string Polynomial::string()
{
    std::stringstream ss;

    for (int i = 0; i < size; i++)
    {
        if (terms[i].second >= 10)
            ss << "(" << terms[i].first << "x^" << terms[i].second << ")";

        if (terms[i].second < 10 && terms[i].second > 1)
            ss << terms[i].first << "x" << superscriptDigit(terms[i].second);

        if (terms[i].second == 1)
            ss << terms[i].first << "x";

        if (terms[i].second == 0)
            ss << terms[i].first;

        if (i + 1 != size)
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
        double term_eval = (terms[i].first * pow(value, terms[i].second));
        sum = sum + (term_eval);
    }

    return sum;
}

// DIFFERENTIATE POLYNOMIAL
void Polynomial::differentiate()
{
    for (int i = 0; i < size; i++)
    {
        if (terms[i].second != 0)
        {
            double new_coeff = terms[i].first * terms[i].second;
            int new_power = terms[i].second - 1;

            terms[i].first = new_coeff;
            terms[i].second = new_power;
        }

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
    std::vector<std::pair<double, int>> differentiatedTerms;

    for (int i = 0; i < size; i++)
    {
        if (terms[i].second != 0)
        {
            double new_coeff = terms[i].first * terms[i].second;
            int new_power = terms[i].second - 1;

            differentiatedTerms.push_back({new_coeff, new_power});
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
        double new_coeff = terms[i].first / (terms[i].second + 1);
        int new_power = terms[i].second + 1;

        terms[i].first = new_coeff;
        terms[i].second = new_power;
    }
}

// RETURN ANTIDIFFERENTIATED POLYNOMIAL
Polynomial Polynomial::antiderivative()
{
    std::vector<std::pair<double, int>> antidifferentiatedTerms;

    for (int i = 0; i < size; i++)
    {
        double new_coeff = terms[i].first / (terms[i].second + 1);
        int new_power = terms[i].second + 1;

        antidifferentiatedTerms.push_back({new_coeff, new_power});
    }

    Polynomial antidifferentiatedPoly(antidifferentiatedTerms);
    return antidifferentiatedPoly;
}

// RETURN INTEGRAL FROM B TO A
double Polynomial::integral(double start, double end)
{
    Polynomial antdifferentiatedPoly = this->antiderivative();

    return (antdifferentiatedPoly.evaluate(end) - antdifferentiatedPoly.evaluate(start));
}

// POLYNOMIAL ADDITION
Polynomial operator+(Polynomial &poly1, Polynomial &poly2)
{
    std::vector<std::pair<double, int>> new_terms;

    int i = 0, j = 0;

    while (i < poly1.size && j < poly2.size)
    {
        if (poly1.terms[i].second == poly2.terms[j].second)
        {
            double coeff_sum = poly1.terms[i].first + poly2.terms[j].first;

            if (coeff_sum != 0)
            {
                new_terms.push_back({coeff_sum, poly1.terms[i].second});
            }
            i++;
            j++;
        }

        else if (poly1.terms[i].second > poly2.terms[j].second)
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
    std::vector<std::pair<double, int>> new_terms;

    int i = 0, j = 0;

    while (i < poly1.size && j < poly2.size)
    {
        if (poly1.terms[i].second == poly2.terms[j].second)
        {
            double coeff_diff = poly1.terms[i].first - poly2.terms[j].first;

            if (coeff_diff != 0)
            {
                new_terms.push_back({coeff_diff, poly1.terms[i].second});
            }
            i++;
            j++;
        }

        else if (poly1.terms[i].second > poly2.terms[j].second)
        {
            new_terms.push_back(poly1.terms[i]);
            i++;
        }

        else
        {
            new_terms.push_back({-poly2.terms[j].first, poly2.terms[j].second});
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
        new_terms.push_back({-poly2.terms[j].first, poly2.terms[j].second});
        j++;
    }

    Polynomial newPolynomial(new_terms);
    return newPolynomial;
}

// Polynomial operator*(double constant, Polynomial &poly)
// {
//     std::vector<Monomial> prod_terms;

//     for (int i = 0; i < poly.size; i++)
//     {
//         prod_terms.push_back(constant * poly.terms[i]);
//     }

//     Polynomial prodPoly(prod_terms);
//     return prodPoly;
// }

// Polynomial operator*(Polynomial &poly, double constant)
// {
//     std::vector<Monomial> prod_terms;

//     for (int i = 0; i < poly.size; i++)
//     {
//         prod_terms.push_back(constant * poly.terms[i]);
//     }

//     Polynomial prodPoly(prod_terms);
//     return prodPoly;
// }

// Polynomial operator*(Monomial &mono, Polynomial &poly)
// {
//     std::vector<Monomial> prod_terms;

//     for (int i = 0; i < poly.size; i++)
//     {
//         prod_terms.push_back(mono * poly.terms[i]);
//     }

//     Polynomial prodPoly(prod_terms);
//     return prodPoly;
// }

// Polynomial operator*(Polynomial &poly, Monomial &mono)
// {
//     std::vector<Monomial> prod_terms;

//     for (int i = 0; i < poly.size; i++)
//     {
//         prod_terms.push_back(mono * poly.terms[i]);
//     }

//     Polynomial prodPoly(prod_terms);
//     return prodPoly;
// }

// // Polynomial operator*(Polynomial& poly1, Polynomial& poly2)
// // {
// //     std::vector<Monomial> prod_terms;

// // }

// Polynomial operator/(Polynomial &poly, double constant)
// {
//     std::vector<Monomial> quotient_terms;

//     for (int i = 0; i < poly.size; i++)
//     {
//         quotient_terms.push_back(poly.terms[i] / constant);
//     }

//     Polynomial prodPoly(quotient_terms);
//     return prodPoly;
// }