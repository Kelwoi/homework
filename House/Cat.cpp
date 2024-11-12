#include "Cat.h"

Cat::Cat(const string& name, const size_t& age, const string& colour, const string& breed, const int weight)
	:Home_pet(name,age,colour,breed), weight(weight)
{
}

void Cat::print() const
{
	cout << "cat N" << id << endl;
	cout << "Name: " << name << endl;
	cout << "age: " << age << endl;
	cout << "colour: " << colour << endl;
	cout << "breed: " << breed << endl;
	cout << "weight: " << weight << endl;
	cout << endl;
}

void Cat::meow() const
{
	cout << name << " meow" << endl;
}
