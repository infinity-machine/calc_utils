#pragma once

class Function
{
public:
    virtual double evaluate(double value) = 0;

    virtual void print() = 0;

    virtual void derivative() = 0;

    virtual void antiderivative() = 0;

    virtual double integral(double start, double end) = 0;
};