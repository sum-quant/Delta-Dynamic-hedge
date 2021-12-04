#pragma once

#include <iostream>
#include<chrono>

void testCallImpliedVolFuntionality();

class Timer

{
public:
    Timer(std::string IVMethod) :ivMethod(IVMethod) {

        start = std::chrono::high_resolution_clock::now();

    }

    ~Timer()
    {
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
        std::cout << "Time taken for Implied volatility computation using " << ivMethod << " is  " << duration.count() << " ms" << endl;

    }
  

private:
   std:: string ivMethod;
    std::chrono::time_point<std::chrono::high_resolution_clock> start;


};

