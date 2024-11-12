#pragma once
#include "Home_pet.h"
class Cat :
    public Home_pet
{
private:
    int weight;
public:
    Cat(const string& name, const size_t& age, const string& colour, const string& breed,const int weight);
    void print() const;
    void meow() const;
};

