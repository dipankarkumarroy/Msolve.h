# Msolve.hpp
This is a header file for command line calculator
## c1.cpp
operation can be solve Addition(+), Subtraction(-), Multiplication(astric symbol), Division(/), Modulus(%), Power of(^).
allowed string: NUM, '(', ')', '+', '-', '/', '%', '^',and astric symbol
format for use Msolve() function:
### format1:
    cout << Msolve("-1-2-3+4+3+5-08+78+54") << "\n";
### format2:
    int x0 = 78;
    cout << Msolve("-1-2-3+4+3+5-08+" + to_string(x0) + "+54") << "\n";
### format3:
    string x1 = to_string(x0);
    cout << Msolve("-1-2-3+4+3+5-08+" + x1 + "+54") << "\n";
### format4:
    cout << Msolve("(ab2+ d_ytc-r+2.0)", 1, 2, 3) << '\n';
    //ab2=1, d_ytc=2,r=3;
    cout<<Msolve("2*(x^5) - 3*(x^4) + 7*(x^3) + 4*(x^2) - 6*(x*y) + 5*(y^3) - 8*(y^2) + 9*y - 12",2,-3);
    //x=2,y=-3;
this format is my choice, use it.

## c3.cpp
open c3 folder and you can see two file one is Msolve.hpp (is a header file) and a c3.cpp(main), And in c3.cpp includes "Msolve.hpp".
to compile this program youneed to type:
    
    g++ -std=c++17 c3.cpp -o abc
and run abc.exe in cmd, Only type

    abc
and press enter.
