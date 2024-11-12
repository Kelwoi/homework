#pragma once
#include "lib.h"
class Home_pet
{
private:
	static size_t last_id;
protected:
	string name;
	size_t age;
	string colour;
	string breed;
	int id;
public:
	Home_pet(const string& name, const size_t& age,const string& colour, const string& breed);
	void print() const;
	~Home_pet();
	void setName(const string& name);
	void setAge(const size_t& age);
	void setColour(const string& colour);
	void setBreed(const string& breed);
	inline string getName() const;
	inline size_t getAge() const;
	inline string getColour() const;
	inline string getBreed() const;
};

