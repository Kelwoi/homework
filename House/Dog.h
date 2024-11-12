#pragma once
#include "Home_pet.h"
class Dog :
    public Home_pet
{
private:
    int height;
public:
    Dog(const string& name, const size_t& age, const string& colour, const string& breed, const int height);
    void print() const;
    void bark() const;
};

