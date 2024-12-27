#include <iostream>
#include "../include/Trinomial.h"
#include "../include/Polynomial.h"
#include <vector>
#include <map>


int main()
{
    // Polynomial poly3 = poly1 + poly2;
    // poly1.print();
    // std::cout << "-----" << std::endl;
    // poly2.print();
    // std::cout << "-----" << std::endl;
    // poly3.print();

    std::vector<std::pair<double, double>> pairvector;

    pairvector.push_back({1, 2});

    std::cout << pairvector[0].second << std::endl;

    Polynomial poly1({1, 3, 4});
    poly1.print();
}