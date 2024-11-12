#include "Home_pet.h"


size_t Home_pet::last_id = 0;
Home_pet::Home_pet(const string& name, const size_t& age, const string& colour, const string& breed)
{
	setName(name);
	setAge(age);
	setColour(colour);
	setBreed(breed);
	id = ++last_id;
}

void Home_pet::print() const
{
	cout << "Animal N" << id << endl;
	cout << "Name: " << name << endl;
	cout << "age: " << age << endl;
	cout << "colour: " << colour << endl;
	cout << "breed: " << breed << endl;
}

Home_pet::~Home_pet()
{
	cout << name << " deleted!" << endl;
}

void Home_pet::setName(const string& name)
{
	this->name = name;
}

void Home_pet::setAge(const size_t& age)
{
	this->age = age;
}

void Home_pet::setColour(const string& colour)
{
	this->colour = colour;
}

void Home_pet::setBreed(const string& breed)
{
	this->breed = breed;
}

inline string Home_pet::getName() const
{
	return this->name;
}

inline size_t Home_pet::getAge() const
{
	return this->age;
}

inline string Home_pet::getColour() const
{
	return this->colour;
}

inline string Home_pet::getBreed() const
{
	return this->breed;
}
