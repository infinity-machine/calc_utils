#include <iostream>
#include "../include/Trinomial.h"
#include "../include/Polynomial.h"
#include <vector>

void divider()
{
    std::cout << "- - - - - - - -" << std::endl;
}


int main()
{
    // Polynomial poly1({1, 3, 5, 6, 7});
    // Polynomial poly2({{3, 4}, {5, 2}, {6, 1}});
    // poly1.print();
    // divider();
    // poly2.print();
    // divider();
    // Polynomial poly3 = poly1 + poly2;
    // divider();
    // poly3.print();
    // divider();
    
    // Polynomial diffpoly3 = poly3.derivative();

    // diffpoly3.print();

    // divider();

    // Polynomial poly4({2, 2, 2});
    // Polynomial antipoly4 = poly4.antiderivative();
    // antipoly4.print();
    // std::cout << poly4.integral(-2, 2);
    // std::cout << antipoly4.evaluate(2) << std::endl;

    Polynomial sqrtpoly({{1, .5}});
    std::cout << sqrtpoly.evaluate(4) << std::endl;

}