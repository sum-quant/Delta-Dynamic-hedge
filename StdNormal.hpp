//Dynamic Delta Hedging
//Standard Normal CDF Implementation Class
// Calculates the CDF of normal distribution using Approximation

#ifndef StdNormal_hpp
#define StdNormal_hpp
#include <stdio.h>
#include "math.h"


#define pi 3.14159265358979323846264338327950288419716939937510


class StdNormalCDF{
private:
    double const a1;
    double const a2;
    double const a3;
    double const a4;
    double const a5;
    
    public :
        StdNormalCDF();
    double operator() (double) const;
    ~StdNormalCDF();
};


#endif /* StdNormal_hpp */
