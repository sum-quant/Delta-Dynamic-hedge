//Dynamic Delta Hedging
//Testing the Functionality of implemented funtions
// precision check of 0.001 in double equals value

#include<iostream>
#include<chrono>
#include"Impvol.hpp"
#include "IVBenchMarking_Test.h"
void testCallImpliedVolFuntionality() {
    //std::cout << "Stock Price=100, Strike Price=80, volatility=0.3, Time to Maturity=0.136, Riskfree Rate=1%" << endl;
   // std::cout << "Call Value 20.18 and Put Value of 0.077516 " << endl;
    impvol v = impvol();
    {
        Timer ob = Timer("Bisection Method");
        double vol1 = v.findRootBisection(20.1862, 100, 0.01, 80, 0.136, 0, "C");
        cout << "Implied Volitality value using Bisection Method is " << vol1<<endl;
    }
    {
        Timer ob = Timer("Secant Method");
        double vol1 = v.findRootSecant(20.1862, 100, 0.01, 80, 0.136, 0, "C");
        cout << "Implied Volitality value using Secant Method is " << vol1 << endl;
    }
    {
        Timer ob = Timer("Newton Raphson Method");
        double vol1 = v.findRootNewton(20.1862, 100, 0.01, 80, 0.136, 0, "C");
        cout << "Implied Volitality value using Newton Raphson Method is " << vol1 << endl;
    }
}

