//Dynamic Delta Hedging
//Implied Volatility Implementation Class
/*
Calculate IV using three methods NewtonRpshon Method, Root Bisection Method, Scant Mehod(yet to be implemented.

A Unit test application will test the performance of all the above three implmentation.


*/
 


#ifndef impvol_hpp
#define impvol_hpp

#include <stdio.h>
#include <string>
#include <iostream>
#include "math.h"
#include "StdNormal.hpp"
#include "Blackscholes.hpp"

using namespace std;

class impvol{
	private:
		double volatility;

	public:
		impvol();
		double findRootNewton(double c, double s, double r, double k, double t, double q, string opt);
		double findRootSecant(double c, double s, double r, double k, double t, double q, string opt);
		double findRootBisection(double v, double s, double r, double k, double t, double q, string opt);
		double funcDiff(double v, double s, double r, double k, double t, double q, string opt, double guess);
		~impvol();

};




#endif
