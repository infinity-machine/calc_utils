#pragma once

class Function
{
public:
    virtual void print() = 0;
    
    virtual double evaluate(double value) = 0;

    virtual void differentiate() = 0;

    virtual void antidifferentiate() = 0;

    virtual double integral(double start, double end) = 0;
};