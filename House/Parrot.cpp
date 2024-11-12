#include "Parrot.h"

Parrot::Parrot(const string& name, const size_t& age, const string& colour, const string& breed, const string& feather_colour)
	:Home_pet(name, age, colour, breed), feather_colour(feather_colour)
{
}
void Parrot::print() const
{
	cout << "parrot N" << id << endl;
	cout << "Name: " << name << endl;
	cout << "age: " << age << endl;
	cout << "colour: " << colour << endl;
	cout << "breed: " << breed << endl;
	cout << "feather colour: " << feather_colour << endl;
	cout << endl;
}

void Parrot::sound() const
{
	cout << name << " makes sound" << endl;
}
