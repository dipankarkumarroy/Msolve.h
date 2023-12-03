#include <iostream>
#include <iomanip>
#include "include/Msolve.hpp"
int main()
{
    std::cout << std::fixed << std::setprecision(10);
    std::cout << Msolve("(2+67+(r+(-3-2-x-09))+2.00009+0.00000345)",34,6) << '\n';
    std::cout<<Msolve("2*(x^5) - 3*(x^4) + 7*(x^3) + 4*(x^2) - 6*(x*y) + 5*(y^3) - 8*(y^2) + 9*y - 12",2,-3);
}
