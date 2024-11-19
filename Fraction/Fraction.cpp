#include <iostream>
#include "Fraction.h"

int main()
{
    fraction one(3, 5);
    fraction two(3, 6);
    fraction three = two * one;
    three.simplify();
    three.print();
}

