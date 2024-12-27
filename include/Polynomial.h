#include <vector>
#include <iostream>

class Polynomial
{
private:
    std::vector<std::pair<double, double>> coeff_pwr;
    int size;

public:
    Polynomial(const std::vector<double> &coefficients);

    Polynomial(const std::vector<std::pair<double, double>> &coefficients_powers);

    void print();

    double evaluate(double value);

    // Polynomial operator+(Polynomial const &polynomial2)
    // {
    //     int more_terms;
    //     int less_terms;

    //     if (size >= polynomial2.size)
    //     {
    //         more_terms = size;
    //         less_terms = polynomial2.size;
    //     }
    //     else
    //     {
    //         more_terms = polynomial2.size;
    //         less_terms = size;
    //     }

    //     std::vector<double> new_coeffs;
    //     std::vector<double> new_pwrs;

    //     for (int i = 0; i < size; i++)
    //     {
    //         for (int j = 0; j < polynomial2.size; j++)
    //         {
    //             if (pwrs[i] == polynomial2.pwrs[j])
    //             {
    //                 new_coeffs.push_back(coeffs[i] + polynomial2.coeffs[j]);
    //                 new_pwrs.push_back(pwrs[i]);
    //             }
    //         }
    //     }
    //     Polynomial newPolynomial(new_coeffs, new_pwrs);
    //     return newPolynomial;
    // }
};