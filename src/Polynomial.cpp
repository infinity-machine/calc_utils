#include "Polynomial.h"
#include "Monomial.h"
#include "unicodePwrs.h"
#include <cmath>
#include <cassert>

// CONSTRUCTOR GIVEN COEFFICIENTS AND RESPECTIVE POWERS
Polynomial::Polynomial(const std::vector<std::pair<double, int>> &monomial_terms)
{
    // assert(terms.size() > 1);
    for(int i = 0; i < monomial_terms.size(); i++) {
        Monomial term(monomial_terms[i]);
        terms.push_back(term);
    }
    size = terms.size();
}

Polynomial::Polynomial(const std::vector<Monomial> &monomial_terms)
{
    // assert(monomial_terms.size() > 1);
    terms = monomial_terms;
    size = monomial_terms.size();
}

// PRINT POLYNOMIAL
void Polynomial::print()
{
    for (int i = 0; i < size; i++)
    {
        if (terms[i].pwr() >= 10)
            std::cout << "(" << terms[i].coeff() << "x^" << terms[i].pwr() << ")";

        if (terms[i].pwr() < 10 && terms[i].pwr() > 0)
            std::cout << terms[i].coeff() << "x" << superscriptDigit(terms[i].pwr());

        if ((i + 1) != size)
            std::cout << " + ";
    }
    std::cout << "\n";
}

// EVALUATE POLYNOMIAL FOR GIVEN VALUE
// double Polynomial::evaluate(double value)
// {
//     double sum = 0;
//     for (int i = 0; i < size; i++)
//     {
//         sum = sum + (terms[i].coeff() * pow(value, terms[i].pwr()));
//     }
//     return sum;
// }

// RETURN DIFFERENTIATED POLYNOMIAL
// Polynomial Polynomial::derivative()
// {
//     std::vector<Monomial> differentiated_terms;
//     for (int i = 0; i < size; i++)
//     {
//         if (terms[i].pwr() != 0)
//         {
//             double coeff = (terms[i].coeff() * terms[i].pwr());
//             int pwr = (terms[i].pwr() - 1);

//             differentiated_terms.push_back(std::make_pair(coeff, pwr));
//         }
//     }
//     Polynomial differentiatedPolynomial(differentiated_terms);
//     return differentiatedPolynomial;
// }

// RETURN ANTIDIFFERENTIATED POLYNOMIAL
// Polynomial Polynomial::antiderivative()
// {
//     std::vector<Monomial> antidifferentiated_terms;
//     for (int i = 0; i < size; i++)
//     {
//         double coeff = (terms[i].coeff() / (terms[i].pwr() + 1));
//         int pwr = (terms[i].pwr() + 1);

//         antidifferentiated_terms.push_back(std::make_pair(coeff, pwr));
//     }
//     Polynomial antidifferentiatedPolynomial(antidifferentiated_terms);
//     return antidifferentiatedPolynomial;
// }

Monomial Polynomial::term(int index)
{
    return terms[index];
}

// RETURN INTEGRAL FROM B TO A
// double Polynomial::integral(double start, double end)
// {
//     Polynomial antideriv = this->antiderivative();
//     return (antideriv.evaluate(end) - antideriv.evaluate(start));
// }

// POLYNOMIAL ADDITION
Polynomial operator+(Polynomial &poly1, Polynomial &poly2)
{
    std::vector<Monomial> new_terms;

    int i = 0, j = 0;
    while (i < poly1.size && j < poly2.size)
    {
        if (poly1.terms[i].pwr() == poly2.terms[i].pwr())
        {
            double coeff_sum = poly1.terms[i].coeff() + poly2.terms[j].coeff();
            if (coeff_sum != 0)
            {
                new_terms.push_back(std::make_pair(coeff_sum, poly1.terms[i].pwr()));
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
// Polynomial operator-(const Polynomial &poly1, const Polynomial &poly2)
// {
//     std::vector<std::pair<double, double>> new_coeff_pwr;

//     int i = 0, j = 0;
//     while (i < poly1.size && j < poly2.size)
//     {
//         if (poly1.coeff_pwr[i].second == poly2.coeff_pwr[j].second)
//         {
//             double coeff_diff = poly1.coeff_pwr[i].first - poly2.coeff_pwr[j].first;
//             if (coeff_diff != 0)
//             {
//                 new_coeff_pwr.push_back(std::make_pair(coeff_diff, poly1.coeff_pwr[i].second));
//             }
//             i++;
//             j++;
//         }
//         else if (poly1.coeff_pwr[i].second > poly2.coeff_pwr[j].second)
//         {
//             new_coeff_pwr.push_back(poly1.coeff_pwr[i]);
//             i++;
//         }
//         else
//         {
//             new_coeff_pwr.push_back(poly2.coeff_pwr[j]);
//             j++;
//         }
//     }

//     while (i < poly1.size)
//     {
//         new_coeff_pwr.push_back(poly1.coeff_pwr[i]);
//         i++;
//     }

//     while (j < poly2.size)
//     {
//         new_coeff_pwr.push_back(poly2.coeff_pwr[j]);
//         j++;
//     }
//     Polynomial newPolynomial(new_coeff_pwr);
//     return newPolynomial;
// }