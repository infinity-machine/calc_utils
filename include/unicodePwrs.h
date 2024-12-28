#include <string>

std::string superscriptDigit(double digit)
{
    switch ((int)digit)
    {
    case 1:
        return "\u2071";

    case 2:
        return "\u00B2";

    case 3:
        return "\u00B3";

    case 4:
        return "\u2074";

    case 5:
        return "\u2075";

    case 6:
        return "\u2076";

    case 7:
        return "\u2077";

    case 8:
        return "\u2078";

    case 9:
        return "\u2079";
    }
    return 0;
}