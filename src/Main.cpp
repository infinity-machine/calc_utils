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

    std::vector<std::pair<double, double>> pairvector{{3, 4}, {5, 6}};
    std::vector<std::pair<double, double>> pairvector2;

    pairvector.push_back({1, 2});

    pairvector2 = pairvector;

    std::cout << pairvector2[0].second << std::endl;

    Polynomial poly1({1, 3, 4});
    Polynomial poly2({{1, 3}, {3, 2}, {4, 1}});
    poly1.print();
    std::cout << "- - - - -" << std::endl;
    poly2.print();
    std::cout << "- - - - -" << std::endl;
    Polynomial poly3 = poly1 + poly2;
    std::cout << "- - - - -" << std::endl;
    poly3.print();
}