#include "Polynomial.h"
#include "Monomial.h"
#include "unicodePwrs.h"
#include <cmath>
#include <cassert>
#include <variant>

// CONSTRUCTOR GIVEN COEFFICIENTS AND RESPECTIVE POWERS
Polynomial::Polynomial(const std::vector<std::pair<double, int>> &monomial_terms)
{
    // assert(terms.size() > 1);
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
double Polynomial::evaluate(double value)
{
    double sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum = sum + (terms[i].evaluate(value));
    }
    return sum;
}

// RETURN DIFFERENTIATED POLYNOMIAL
Polynomial Polynomial::derivative()
{
    std::vector<Monomial> differentiated_terms;
    for (int i = 0; i < size; i++)
    {
        if (terms[i].pwr() != 0)
            differentiated_terms.push_back(terms[i].derivative());
    }
    Polynomial differentiatedPolynomial(differentiated_terms);
    return differentiatedPolynomial;
}

// RETURN ANTIDIFFERENTIATED POLYNOMIAL
Polynomial Polynomial::antiderivative()
{
    std::vector<Monomial> antidifferentiated_terms;
    for (int i = 0; i < size; i++)
    {
        antidifferentiated_terms.push_back(terms[i].antiderivative());
    }
    Polynomial antidifferentiatedPolynomial(antidifferentiated_terms);
    return antidifferentiatedPolynomial;
}

Polynomial Polynomial::likeTerms()
{
    std::vector<Monomial> combined_terms;
    std::vector<Monomial> copied_terms = terms;
    double coeff_sum = 0;

    // std::cout << copied_terms[0].pwr() << std::endl;
    // copied_terms.erase(copied_terms.begin());
    // std::cout << copied_terms[0].pwr() << std::endl;

    while (copied_terms.size() > 0)
    {
        if (copied_terms.size() > 1)
        {
            if (copied_terms[0].pwr() == copied_terms[1].pwr())
            {
                coeff_sum = copied_terms[0].coeff() + copied_terms[1].coeff();
                Monomial combined_term({coeff_sum, copied_terms[0].pwr()});
                combined_terms.push_back(combined_term);

                copied_terms.erase(copied_terms.begin());
                copied_terms.erase(copied_terms.begin() + 1);
            }

            // else if (copied_terms[0].pwr() > copied_terms[1].pwr())
            // {
            //     combined_terms.push_back(terms[0]);
            //     copied_terms.erase(copied_terms.begin());
            // }

            // else
            // {
            //     combined_terms.push_back(copied_terms[1]);
            //     copied_terms.erase(copied_terms.begin() + 1);
            // }
        }

        else
        {
            combined_terms.push_back(copied_terms[0]);
            copied_terms.erase(copied_terms.begin());
        }
    }

    Polynomial combinedPolynomial(combined_terms);
    return combinedPolynomial;
}

// for (int i = 0; i < size; i++)
// {
// if (copied_terms[i].pwr() == copied_terms[i + 1].pwr())
// {
//     coeff_sum = copied_terms[0].coeff() + copied_terms[i].coeff();
//     Monomial combined_term({coeff_sum, copied_terms[0].pwr()});
//     combined_terms.push_back(combined_term);
// }

//     else if (copied_terms[i].pwr() > copied_terms[i + 1].pwr())
//     {
//         combined_terms.push_back(terms[i]);
//         copied_terms.erase(copied_terms.begin() + i);
//     }

//     else
//     {
//         combined_terms.push_back(copied_terms[i + 1]);
//         copied_terms.erase(copied_terms.begin() + i);
//     }
// }

// Polynomial combinedPolynomial(combined_terms);
// return combinedPolynomial;

Monomial Polynomial::term(int index)
{
    return terms[index];
}

// RETURN INTEGRAL FROM B TO A
double Polynomial::integral(double start, double end)
{
    Polynomial antideriv = this->antiderivative();
    return (antideriv.evaluate(end) - antideriv.evaluate(start));
}

// POLYNOMIAL ADDITION
Polynomial operator+(Polynomial &poly1, Polynomial &poly2)
{
    std::vector<Monomial> conglomerated_terms;

    int i = 0, j = 0;

    while (i < poly1.size || j < poly2.size)
    {
        if (i < poly1.size)
        {
            conglomerated_terms.push_back(poly1.terms[i]);
            i++;
        }

        if (j < poly2.size)
        {
            conglomerated_terms.push_back(poly2.terms[j]);
            j++;
        }
    }

    Polynomial conglomeratedPolynomial(conglomerated_terms);
    conglomeratedPolynomial.print();
    Polynomial combinedPolynomial = conglomeratedPolynomial.likeTerms();
    return combinedPolynomial;
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