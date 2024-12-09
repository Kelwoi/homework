#pragma once
#include <iostream>
#include <string>
using namespace std;

class HotDrink {
protected:
    string name;
    int waterRequired;
    int sugarRequired;
    int price;

public:
    HotDrink(const string& name, const int& water, const int& sugar, const int& p)
        : name(name), waterRequired(water), sugarRequired(sugar), price(p) {}

    virtual void displayInfo() {
        cout << name << ": price - " << price << " dol\n";
    }

    virtual int getPrice() { return price; }
    virtual int getWaterRequired() { return waterRequired; }
    virtual int getSugarRequired() { return sugarRequired; }
    virtual string getName() { return name; }
};



