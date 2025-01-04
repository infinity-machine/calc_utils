#pragma once

class Fraction
{
private:
    int numerator;
    int denominator;

public:
    Fraction(double num, double denom);
    Fraction (double decimal);
    void print();
    double decimal();
    void reduce();
    void reciprocal();
    Fraction getReciprocal();


    friend Fraction operator+(Fraction fraction1, Fraction fraction2);
    friend Fraction operator-(Fraction fraction1, Fraction fraction2);
    friend Fraction operator*(Fraction fraction1, Fraction fraction2);
    friend Fraction operator/(Fraction fraction1, Fraction fraction2);
};