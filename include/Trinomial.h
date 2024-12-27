class Trinomial 
{
private:
    int coeff_a;
    int coeff_b;
    int coeff_c;

public:
    Trinomial(double a, double b, double c);
    double evaluate(double value);
    double discriminant();
    void roots();
};