#include "MathFunctions.h"
#include <iostream>

double mysqrt(double x) 
{
    if (x <= 0) {
        return 0;
    }

    double result = x;

    // do ten iterations
    for (int i = 0; i < 10; ++i) {
        if (result <= 0) {
            result = 0.1;
        }
        double delta = x - (result * result);
#if defined (HAVE_LOG) && defined (HAVE_EXP)
        result = exp(log(x)*0.5);
#else
        result = result + 0.5 * delta / result;
#endif
        std::cout << "Computing sqrt of " << x << " to be " << result << std::endl;
    }
    return result;
}