//Dynamic Delta Hedging
//Black Scholes Implementation Class
// calculates call value, delta call, first derivative of the call option
// calculates put value, delta put, first derivative of the put option


#ifndef blackscholes_hpp
#define blackscholes_hpp

#include <stdio.h>
#include <iostream>
#include "math.h"
#include "StdNormal.hpp"
using namespace std;

class blackscholes{
	private:
		double stock;
		double riskFree;
		double strike;
		double volatility;
		double timetomaturity;
		double dividend;

	public:
		blackscholes();
		blackscholes(double s, double r, double k, double v, double t, double d);

		double callValue();
		double deltaCall();

		double putValue();
		double deltaPut();

		double firstDer();

		~blackscholes();
};

#endif

