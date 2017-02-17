#include <iostream>

#include "term.h"


int main()
{
    Term a(3, 5, "x");
    Term b(5, 5, "x");
    a += b;
    std::cout << a << '+' << b << std::endl;

    Term c = Term();
    std::cin >> c;

    std::cout << c << std::endl;
}

