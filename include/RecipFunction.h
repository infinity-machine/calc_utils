#include "Monomial.h"
#include "Polynomial.h"

class ReciprocalFunction
{
private:
    double coefficient;
    int degree;
    std::vector<Monomial> terms;
    
public:
    ReciprocalFunction(const std::pair<double, int> &coefficient_power);
    ReciprocalFunction(Monomial &mono);
    // ReciprocalFunction(const Polynomial poly);

    void print();
};