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

    Polynomial derivative();

    Polynomial antiderivative();

    double integral(double end, double start);

    Polynomial operator+(Polynomial const &polynomial2)
    {
        std::vector<std::pair<double, double>> new_coeff_pwr;

        int i = 0, j = 0;
        while (i < size && j < polynomial2.size)
        {
            if (coeff_pwr[i].second == polynomial2.coeff_pwr[j].second)
            {
                double coeff_sum = coeff_pwr[i].first + polynomial2.coeff_pwr[j].first;
                if (coeff_sum != 0)
                {
                    new_coeff_pwr.push_back(std::make_pair(coeff_sum, coeff_pwr[i].second));
                }
                i++;
                j++;
            }
            else if (coeff_pwr[i].second > polynomial2.coeff_pwr[j].second)
            {
                new_coeff_pwr.push_back(coeff_pwr[i]);
                i++;
            }
            else {
                new_coeff_pwr.push_back(polynomial2.coeff_pwr[j]);
                j++;
            }
        }

        while (i < size) {
            new_coeff_pwr.push_back(coeff_pwr[i]);
            i++;
        }

        while (j < polynomial2.size) {
            new_coeff_pwr.push_back(polynomial2.coeff_pwr[j]);
            j++;
        }
        Polynomial newPolynomial(new_coeff_pwr);
        return newPolynomial;
    }

    Polynomial operator-(Polynomial const &polynomial2)
    {
        std::vector<std::pair<double, double>> new_coeff_pwr;

        int i = 0, j = 0;
        while (i < size && j < polynomial2.size)
        {
            if (coeff_pwr[i].second == polynomial2.coeff_pwr[j].second)
            {
                double coeff_diff = coeff_pwr[i].first - polynomial2.coeff_pwr[j].first;
                if (coeff_diff != 0)
                {
                    new_coeff_pwr.push_back(std::make_pair(coeff_diff, coeff_pwr[i].second));
                }
                i++;
                j++;
            }
            else if (coeff_pwr[i].second > polynomial2.coeff_pwr[j].second)
            {
                new_coeff_pwr.push_back(coeff_pwr[i]);
                i++;
            }
            else {
                new_coeff_pwr.push_back(polynomial2.coeff_pwr[j]);
                j++;
            }
        }

        while (i < size) {
            new_coeff_pwr.push_back(coeff_pwr[i]);
            i++;
        }

        while (j < polynomial2.size) {
            new_coeff_pwr.push_back(polynomial2.coeff_pwr[j]);
            j++;
        }
        Polynomial newPolynomial(new_coeff_pwr);
        return newPolynomial;
    }
};