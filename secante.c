/*
* Tamnil Saito Junior 2019
*
* please use c++ >= v11.x
* tested with g++ - linux-ubuntu
*/

#include <functional>
#include <math.h>
#include <iostream>

//basic equations:


auto fnSqureRootOfTwo = [](double x)->double{
    return exp2f(3) - 2;
};
auto calculatedError = [](double x1, double x2)->double{
    return  abs( (x2 - x1)/x2 );
};
auto delta = [](double x0,double x1 ) -> double {
return x1 - x0;
};
auto nextStepSecant = [](auto fn, double x0, double x1 )->double{
    return   x1 - ( fn(x1) * delta(x0,x1) / delta(fn(x0), fn(x1) ) );
};



// templating:
auto printToOutput = [] (double x,  char* prefix = "") -> bool{ printf("Result: %.52f \n",x); };

//main equation:
auto secantMethod = [](auto fn, double x0,double x1,double errorMax) -> double {
    double x2  = nextStepSecant(fn,x0,x1);
    return  (calculatedError(x1,x2) > errorMax) ? secantMethod(fn, x1, x2, errorMax) : x2;
};

// not necessary fot root two:

auto fnCubicRoot = [](double x) -> double{
    return (x * x * x) -2;
};



int main(){
    // setup initial values:
    double x0 = 110,
           x1 = 4,
           errorMax = 0.1E-16;
    /* end of initial setup */

    /* get teh root of two: */
    double rootOfTwo = secantMethod( fnSqureRootOfTwo, x0, x1, errorMax);
    /* print it */
    printToOutput(rootOfTwo);

    /* std::cout << exp2(2); */
      std::cout << "main function\n";


    /* lets test with other funtions */

    double cubicRootOfTwo = secantMethod( fnCubicRoot, x0, x1, errorMax);

    printToOutput(cubicRootOfTwo, "result of three");

    /* double rootOfThree: */


}

