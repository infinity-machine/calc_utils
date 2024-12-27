#include <iostream>
#include "../include/Trinomial.h"
#include "../include/Polynomial.h"
#include <vector>


int main()
{
    Trinomial trinomial1(4, 3, -3);

    std::vector<double> coeffs = {2, 3, 1, 2};
    std::vector<double> pwrs = {4, 3, 2, 1};

    Polynomial poly1(coeffs, pwrs);
    Polynomial poly2({1, 1, 1, 1});
    std::cout << poly1.evaluate(2) << std::endl;
    std::cout << poly2.evaluate(2) << std::endl;

    Polynomial poly3 = poly1 + poly2;
    poly1.print();
    std::cout << "-----" << std::endl;
    poly2.print();
    std::cout << "-----" << std::endl;
    poly3.print();
}