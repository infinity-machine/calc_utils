#include "Polynomial.h"
#include <cmath>
#include "unicodePwrs.h"

// CONSTRUCTOR GIVEN COEFFICIENTS
Polynomial::Polynomial(const std::vector<double> &coefficients)
{
    size = coefficients.size();
    for (int i = 0; i < coefficients.size(); i++)
    {
        double power = size - (1 + i);
        coeff_pwr.push_back({coefficients[i], power});
    }
}

// CONSTRUCTOR GIVEN COEFFICIENTS AND RESPECTIVE POWERS
Polynomial::Polynomial(const std::vector<std::pair<double, double>> &coefficients_powers)
{
    coeff_pwr = coefficients_powers;
    size = coeff_pwr.size();
}

// PRINT POLYNOMIAL
void Polynomial::print()
{
    for (int i = 0; i < size; i++)
    {
        if (coeff_pwr[i].second >= 10)
            std::cout << "(" << coeff_pwr[i].first << "x^" << coeff_pwr[i].second << ")";

        if (coeff_pwr[i].second < 10 && coeff_pwr[i].second > 0)
            std::cout << coeff_pwr[i].first << "x" << superscriptDigit(coeff_pwr[i].second);

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
        sum = sum + (coeff_pwr[i].first * pow(value, coeff_pwr[i].second));
    }
    return sum;
}

// RETURN DIFFERENTIATED POLYNOMIAL
Polynomial Polynomial::derivative()
{
    std::vector<std::pair<double, double>> differentiated_coeff_pwr;
    for (int i = 0; i < size; i++)
    {
        if (coeff_pwr[i].second != 0)
        {
            double coeff = (coeff_pwr[i].first * coeff_pwr[i].second);
            double pwr = (coeff_pwr[i].second - 1);

            differentiated_coeff_pwr.push_back(std::make_pair(coeff, pwr));
        }
    }
    Polynomial differentiatedPolynomial(differentiated_coeff_pwr);
    return differentiatedPolynomial;
}

// RETURN ANTIDIFFERENTIATED POLYNOMIAL
Polynomial Polynomial::antiderivative()
{
    std::vector<std::pair<double, double>> antidifferentiated_coeff_pwr;
    for (int i = 0; i < size; i++)
    {
        double coeff = (coeff_pwr[i].first / (coeff_pwr[i].second + 1));
        double pwr = (coeff_pwr[i].second + 1);

        antidifferentiated_coeff_pwr.push_back(std::make_pair(coeff, pwr));
    }
    Polynomial antidifferentiatedPolynomial(antidifferentiated_coeff_pwr);
    return antidifferentiatedPolynomial;
}

// RETURN INTEGRAL FROM B TO A
double Polynomial::integral(double start, double end)
{
    Polynomial antideriv = this->antiderivative();
    return (antideriv.evaluate(end) - antideriv.evaluate(start));
}

// POLYNOMIAL ADDITION
Polynomial operator+(const Polynomial &poly1, const Polynomial &poly2)
{
    std::vector<std::pair<double, double>> new_coeff_pwr;

    int i = 0, j = 0;
    while (i < poly1.size && j < poly2.size)
    {
        if (poly1.coeff_pwr[i].second == poly2.coeff_pwr[j].second)
        {
            double coeff_sum = poly1.coeff_pwr[i].first + poly2.coeff_pwr[j].first;
            if (coeff_sum != 0)
            {
                new_coeff_pwr.push_back(std::make_pair(coeff_sum, poly1.coeff_pwr[i].second));
            }
            i++;
            j++;
        }
        else if (poly1.coeff_pwr[i].second > poly2.coeff_pwr[j].second)
        {
            new_coeff_pwr.push_back(poly1.coeff_pwr[i]);
            i++;
        }
        else
        {
            new_coeff_pwr.push_back(poly2.coeff_pwr[j]);
            j++;
        }
    }

    while (i < poly1.size)
    {
        new_coeff_pwr.push_back(poly1.coeff_pwr[i]);
        i++;
    }

    while (j < poly2.size)
    {
        new_coeff_pwr.push_back(poly2.coeff_pwr[j]);
        j++;
    }
    Polynomial newPolynomial(new_coeff_pwr);
    return newPolynomial;
}

// POLYNOMIAL SUBTRACTION
Polynomial operator-(const Polynomial &poly1, const Polynomial &poly2)
{
    std::vector<std::pair<double, double>> new_coeff_pwr;

    int i = 0, j = 0;
    while (i < poly1.size && j < poly2.size)
    {
        if (poly1.coeff_pwr[i].second == poly2.coeff_pwr[j].second)
        {
            double coeff_diff = poly1.coeff_pwr[i].first - poly2.coeff_pwr[j].first;
            if (coeff_diff != 0)
            {
                new_coeff_pwr.push_back(std::make_pair(coeff_diff, poly1.coeff_pwr[i].second));
            }
            i++;
            j++;
        }
        else if (poly1.coeff_pwr[i].second > poly2.coeff_pwr[j].second)
        {
            new_coeff_pwr.push_back(poly1.coeff_pwr[i]);
            i++;
        }
        else
        {
            new_coeff_pwr.push_back(poly2.coeff_pwr[j]);
            j++;
        }
    }

    while (i < poly1.size)
    {
        new_coeff_pwr.push_back(poly1.coeff_pwr[i]);
        i++;
    }

    while (j < poly2.size)
    {
        new_coeff_pwr.push_back(poly2.coeff_pwr[j]);
        j++;
    }
    Polynomial newPolynomial(new_coeff_pwr);
    return newPolynomial;
}