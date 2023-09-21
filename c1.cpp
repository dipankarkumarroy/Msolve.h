#include <iostream>
#include "include/Msolve.hpp"
using namespace std;
int main()
{
    int x0 = 78;
    string x1 = to_string(x0);
    cout << Msolve("-1-2-3+4+3+5-08+78+54") << "\n";
    cout << Msolve("-1-2-3+4+3+5-08+" + to_string(x0) + "+54") << "\n";
    cout << Msolve("-1-2-3+4+3+5-08+" + x1 + "+54") << "\n";
    cout << Msolve("(ab2+ d_y tc-r+2.0)", 1, 2.5, 3) << '\n';
}
