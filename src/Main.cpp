#include <iostream>
#include "../include/Trinomial.h"
#include "../include/Polynomial.h"
#include <vector>


int main()
{
    Trinomial trinomial1(4, 3, -3);

    std::vector<double> coeffs = {1, 1, 1, 0};
    std::vector<double> pwrs = {3, 2, 1, 0};

    Polynomial poly1(coeffs, pwrs);
    Polynomial poly2(coeffs);
    // poly1.print();
    std::cout << poly1.evaluate(2) << std::endl;
    // std::cout << trinomial1.evaluate(-2) << std::endl;
    std::cout << poly2.evaluate(2) << std::endl;
}