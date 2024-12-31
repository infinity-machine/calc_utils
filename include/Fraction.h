#pragma once

class Fraction
{
private:
    int numerator;
    int denominator;

public:
    Fraction(double num, double denom);
    void print();
    double decimal();
    void reduce();

    // friend Fraction operator+(Fraction fraction1, Fraction fraction2);
};