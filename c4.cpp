#include <iostream>
#include <iomanip>
#include "include/Msolve.hpp"
int main()
{
    std::cout << std::fixed << std::setprecision(10);
    std::cout << Msolve("(2+67+(r+(-3-2-x-09))+2.00009+0.00000345)",34,6) << '\n';
}
