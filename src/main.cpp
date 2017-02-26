#include <iostream>

#include "polynomial.h"


int main()
{
    Polynomial poly;
    Polynomial poly2;
    std::cin >> poly;
    std::cin >> poly2;
    std::cout << poly;
    std::cout << poly2;

    poly += poly2;
    std::cout << poly << std::endl;
    /*Term a(3, 5, "x");
    Term b(5, 5, "x");
    a += b;
    std::cout << a << '+' << b << std::endl;

    Term c = Term();
    std::cin >> c;

    std::cout << c << std::endl;*/
}

