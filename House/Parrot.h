#pragma once
#include "Home_pet.h"
class Parrot :
    public Home_pet
{
private:
    string feather_colour;
public:
    Parrot(const string& name, const size_t& age, const string& colour, const string& breed, const string& feather_colour);
    void print() const;
    void sound() const;
};

