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
    void derivative();
    void antiderivative();
    double integral();
};