
#include<iostream>
#include"Impvol.hpp"
#include "StdNormal.hpp"
#include "Blackscholes.hpp" 

using namespace std;

impvol::impvol() {
    volatility = 0.0;
}
double impvol :: findRootNewton(double c, double s, double r, double k, double t, double q, string opt){
	double tolerance = .001;
	double initialGuess = 0.25;
	volatility = 0.0;
	blackscholes bs = blackscholes(s, r, k, initialGuess, t, q);
	//std::cout << "imp vol" <<endl;
	double optval = 0.0;
	if(opt == "C") {
		optval = bs.callValue();
	//	std::cout << optval << " "<<r <<endl;
	}
	else{
		optval = bs.putValue();
	//	std::cout << optval << " "<<r <<endl;
	}
	double diff = c- optval;
	double firstDer = bs.firstDer();
	double ratio = diff/firstDer;
	volatility = initialGuess + ratio;
//	std::cout << "first der " << firstDer << " "<< ratio << " diff " << volatility << endl;
 	while( (abs(volatility-initialGuess) >tolerance) && (abs(diff)> tolerance)){
		initialGuess = volatility;
		blackscholes bs = blackscholes(s, r, k, initialGuess, t, q);
		if(opt == "C") {
			optval = bs.callValue();
		}
		else{
			optval = bs.putValue();
		}
    	diff = c-optval;
    	firstDer = bs.firstDer();
		ratio = diff/firstDer;
		volatility = initialGuess + ratio;
	}
	return volatility;
}
//Functor() ---implement???
double impvol::findRootSecant(double c, double s, double r, double k, double t, double q, string opt) {
	double tolerance = .0001;
	double initialGuess0 = 0.25;
	double initialGuess1 = 0.3;

	volatility = 0.0;
	blackscholes bs0 = blackscholes(s, r, k, initialGuess0, t, q);
	blackscholes bs1 = blackscholes(s, r, k, initialGuess1, t, q);

	//std::cout << "imp vol" <<endl;
	double optval0,optval1 = 0.0;
	if (opt == "C") {
		optval0 = bs0.callValue();
		optval1 = bs1.callValue();
		//	std::cout << optval << " "<<r <<endl;
	}
	else {
		optval0 = bs0.callValue();
		optval1 = bs1.callValue();
		//	std::cout << optval << " "<<r <<endl;
	}
	double diff = c - optval1;
	double firstDer = (optval0 - optval1) / (initialGuess1 - initialGuess0);
	double ratio = diff / firstDer;
	volatility = initialGuess1 + ratio;  //volatility = initialGuess1 - ratio;
	//	std::cout << "first der " << firstDer << " "<< ratio << " diff " << volatility << endl;
	while ((abs(volatility - initialGuess1) > tolerance) && (abs(diff) > tolerance)) {
		initialGuess0 = initialGuess1;
		initialGuess1 = volatility;
		blackscholes bs0 = blackscholes(s, r, k, initialGuess0, t, q);
		blackscholes bs1 = blackscholes(s, r, k, initialGuess1, t, q);
		if (opt == "C") {
			optval0 = bs0.callValue();
			optval1 = bs1.callValue();
			//	std::cout << optval << " "<<r <<endl;
		}
		else {
			optval0 = bs0.callValue();
			optval1 = bs1.callValue();
			//	std::cout << optval << " "<<r <<endl;
		}
		double diff = c - optval1;
		double firstDer = (optval0 - optval1) / (initialGuess1 - initialGuess0);
		double ratio = diff / firstDer;
		volatility = initialGuess1 + ratio;//volatility = initialGuess1 - ratio;
	}
	return volatility;
}

impvol :: ~impvol() {
}
double impvol::funcDiff(double v, double s, double r, double k, double t, double q, string opt, double guess) {
    blackscholes bs = blackscholes(s, r, k, guess, t, q);
    double optval = 0.0;
    if (opt == "C") {
        optval = bs.callValue();
    }
    else {
        optval = bs.putValue();
    }
    return v - optval;
}
double impvol::findRootBisection(double v, double s, double r, double k, double t, double q, string opt) {
    double epsilon = 0.0001;
    double lowerLimit = 0.0001;
    double upperLimit = 1.0;
    double avgVal = (upperLimit + lowerLimit) / 2.0;

    if (funcDiff(v, s, r, k, t, q, opt, lowerLimit) < 0.0) {
        avgVal = lowerLimit / 2.0;
    }
    // std::cout <<"hehy" << funcDiff(v,s,r,k,t,q,opt, upperLimit)<< endl;
    while (funcDiff(v, s, r, k, t, q, opt, upperLimit) >= 0.0) {
        lowerLimit = 1.0;
        upperLimit = 2.0 * upperLimit;
    }

    int i = 0;
    while ((upperLimit - lowerLimit) > epsilon && i <= 100) {
        i++;
        if ((funcDiff(v, s, r, k, t, q, opt, upperLimit) * funcDiff(v, s, r, k, t, q, opt, avgVal)) > 0.0) {
            upperLimit = avgVal;
        }
        else if ((funcDiff(v, s, r, k, t, q, opt, lowerLimit) * funcDiff(v, s, r, k, t, q, opt, avgVal)) > 0.0) {
            lowerLimit = avgVal;
        }
        avgVal = (upperLimit + lowerLimit) / 2.0;
    }

    return avgVal;
}