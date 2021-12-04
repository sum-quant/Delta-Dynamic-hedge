#include "StdNormal.hpp"
#include<iostream>



StdNormalCDF::StdNormalCDF() :a1(0.31938153), a2(-0.356563782), a3(1.781477937), a4(-1.821255978), a5(1.330274429) {}
StdNormalCDF::~StdNormalCDF() {}


double StdNormalCDF :: operator()(double x)const {
    double l = fabs(x);
    double z = 1 / (1 + 0.2316419 * l);
    double r = a1 * z + a2 * pow(z, 2) + a3 * pow(z, 3) + a4 * pow(z, 4) + a5 * pow(z, 5);
    double n = 1 - 1 / (sqrt(2 * pi)) * exp(-pow(l, 2) / 2) * r;
    if (x >= 0)
        return n;
    else
        return (1 - n);
}