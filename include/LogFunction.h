#include <cmath>

class LogFunction
{
private:
    int base;

public:
    LogFunction(int log_base);
    void print();
    double evaluate(double value);

    // NEED TO HANDLE COMPOSITE LOG FUNCTIONS
    // DERIVATIVE OF A LOG FUNCTION CAN BE A RECIPROCAL FUNCITON OR RATIONAL FUNCTION

    // Function* derivative();
    // void antiderivative();
    // double integral();
};