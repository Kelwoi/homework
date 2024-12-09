#pragma once


#include "Coffee.h"
#include "Tea.h"
#include "Cappuccino.h"

class VendingMachine {
private:
    int water;
    int sugar;
    int cash;
    int coffeeCount, teaCount, cappuccinoCount;
    Coffee coffee;
    Tea tea;
    Cappuccino cappuccino;

public:
    VendingMachine() : water(1000), sugar(500), cash(0),
        coffeeCount(0), teaCount(0), cappuccinoCount(0) {}

    void adminMode();
    void userMode();
    void processOrder(HotDrink& drink);
    void ChangePrice(HotDrink& drink, int newPrice);
};


