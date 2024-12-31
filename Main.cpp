#include <iostream>
#include "../include/Polynomial.h"
#include "Monomial.h"
#include <vector>
#include <map>
#include "LogFunction.h"
#include "ReciprocalFunction.h"
#include "Fraction.h"
#include <numeric>

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

    // Monomial mono({3, 2});
    // mono.print();
    // std::cout << mono.string();
    // mono.antiderivative();
    // mono.derivative();
    // std::cout << mono.integral(-1, 3) << std::endl;
    // mono.print();

    // Polynomial poly1({{2, 2}, {2, 1}, {2, 0}});
    // Polynomial poly2 = poly1;
    // poly2.print();
    // std::cout << poly1.string() << std::endl;
    // divider();
    // poly1.derivative();
    // poly1.print();
    // std::cout << poly1.integral(-2, 2) << std::endl;

    Monomial mono({2, 4});
    // Monomial mono2 = mono;

    Polynomial poly1({{1, 2}, {2, 3}});

    ReciprocalFunction<Monomial> recip1(3, mono);

    // std::cout << (int)2.4 % 2 << std::endl;

    recip1.print();

    // ReciprocalFunction<Polynomial> recip2(poly1);
    // recip2.print();

    // Fraction afrac(15, 75);
    // std::cout << std::gcd(15, 75) << std::endl;
    // afrac.reduce();
    // afrac.print();

    // std::cout << mono.integral(-2, 2);

    // ReciprocalFunction recip1({2, 3});

    // recip1.print();

    // poly1.addTerm(mono);

    // poly1.print();

    // Polynomial poly({{2, 2}, {4, 1}});
    // Polynomial poly2({{3, 2}, {3, 1}});

    // poly.orderPwrs();

    // (poly - poly2).print();

    // LogFunction aLog(2);

    // std::cout << poly.evaluate(2) << std::endl;

    // std::cout << aLog.evaluate(poly.evaluate(2)) << std::endl;

    // aLog.print();

    // 5 * mono;
    // mono * 5;
    // (mono*5).print();
}