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

    Polynomial operator+(Polynomial const &polynomial2)
    {
        std::vector<std::pair<double, double>> new_coeff_pwr;

        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < polynomial2.size; j++)
            {
                if (coeff_pwr[i].second == polynomial2.coeff_pwr[j].second)
                {
                    new_coeff_pwr.push_back(
                        std::make_pair(
                            (coeff_pwr[i].first + polynomial2.coeff_pwr[j].first), coeff_pwr[i].second));
                }
            }
        }
        Polynomial newPolynomial(new_coeff_pwr);
        return newPolynomial;
    }
};