#include "Dog.h"

Dog::Dog(const string& name, const size_t& age, const string& colour, const string& breed, const int height)
	:Home_pet(name, age, colour, breed), height(height)
{
}

void Dog::print() const
{
	cout << "dog N" << id << endl;
	cout << "Name: " << name << endl;
	cout << "age: " << age << endl;
	cout << "colour: " << colour << endl;
	cout << "breed: " << breed << endl;
	cout << "height: " << height << endl;
	cout << endl;
}

void Dog::bark() const
{
	cout << name << " Bark" << endl;
}
