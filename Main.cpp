#include <iostream>
#include "../include/Polynomial.h"
#include "Monomial.h"
#include <vector>
#include <map>

void divider()
{
    std::cout << "- - - - - - - -" << std::endl;
}


int main()
{
    // Polynomial poly1({{1, 5}, {2, 4}});
    // poly1.print();
    // divider();
    // Polynomial combinedPoly = poly1.likeTerms();
    // combinedPoly.print();

    // Polynomial combined = poly1.likeTerms();
    // combined.print();
    // Polynomial poly2({{3, 4}, {5, 3}, {6, 2}, {1, 1}});
    // poly2.print();
    // divider();
    // std::cout << poly2.term(1).coeff() << std::endl;
    // divider();
    // Polynomial poly3 = poly1 - poly2;
    // divider();
    // poly3.print();
    // divider();
    
    // Polynomial diffpoly3 = poly3.derivative();

    // diffpoly3.print();

    // divider();

    // Polynomial poly4({{1, 1}, {3, 2}, {2, 3}});
    // poly4.orderPwrs();
    // poly4.print();
    // Polynomial antipoly4 = poly4.antiderivative();
    // antipoly4.print();
    // std::cout << poly4.integral(-2, 2);
    // std::cout << antipoly4.evaluate(2) << std::endl;

    // Monomial mono({2, 1});
    // mono.antiderivative();
    // mono.derivative();
    // std::cout << mono.integral(-1, 3) << std::endl;
    // mono.print();

    Polynomial poly1({{2, 2}, {2, 1}, {2, 0}});
    poly1.print();
    divider();
    // poly1.derivative();
    // poly1.print();
    std::cout << poly1.integral(-2, 2) << std::endl;
}