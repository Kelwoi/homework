#pragma once
#include <iostream>
#include<string>
using namespace std;
class contact {
private:
	char* name = nullptr;
	size_t worknumber;
	size_t homenumber;
	size_t number;
	char* extra_info = nullptr;
public:
	~contact()
	{
		if (this->name != nullptr)
			delete[] this->name;
		if (this->extra_info != nullptr)
			delete[] this->extra_info;
	}
		contact(const char* name, size_t worknumber,  size_t homenumber,  size_t number, const char* extra_info)
		:worknumber{ worknumber }, homenumber{ homenumber }, number{ number }
		{
		copyStr(this->name, name);
		copyStr(this->extra_info, extra_info);
		}
	void print() {
		cout << "Pib: " << this->name << endl;
		cout << "worknumber: " << to_string(this->worknumber) << endl;
		cout << "homenumber: " << to_string(this->homenumber) << endl;
		cout << "personal number: " << to_string(this->number) << endl;
		cout << "extra info: " << this->extra_info << endl;
	}
	 const char* getName() const {
		return this->name;
	}
private:
	void copyStr(char*& dest, const char* source) {
		if (dest != nullptr) {
			delete[] dest;
		}
		size_t size = strlen(source) + 1;
		dest = new char[size];
		strcpy_s(dest, size, source);
	}
	inline bool isvalid(const char* source)
	{
		return name != nullptr and name[0] != '\0';
	}
};
class phoneBook {
private:
	contact* contacts[100];
	int count;
public:
	~phoneBook() {
		for (int i = 0; i < count; ++i) {
			delete contacts[i];
		}
	}
	phoneBook()
	: count(0) 
	{}
	void add_contact(const char* name,  size_t worknumber,  size_t homenumber,  size_t number, const char* extra_info) {
		if (count < 100) {
			contacts[count] = new contact(name, worknumber, homenumber, number, extra_info);
			count++;
			cout << "Added succesfully!" << endl;
		}
		else
			cout << "book have too much";

	}

	const void show_contacts() const {
		for (size_t i = 0; i < count; i++)
		{
			cout << endl;
			cout << "==============" << endl;
			cout << "contact " << i + 1 << endl;
			contacts[i]->print();
			cout << "==============" << endl;
			cout << endl;
		}
	}
	const void find(const char* name) {
		for (size_t i = 0; i < count; i++)
		{

			if (strcmp(contacts[i]->getName(), name) == 0) {
				contacts[i]->print();
				return;
			}
			else {
				cout << "Found nothing" << endl;
			}
		}
	}
	const void delete_cont(const char* name) {
		for (size_t i = 0; i < count; i++)
		{
			if (strcmp(contacts[i]->getName(), name) == 0) {
				delete contacts[i];
				for (int j = i; j < count - 1; ++j) {
					contacts[j] = contacts[j + 1];
				}
				contacts[--count] = nullptr;
				std::cout << "Contact deleted.\n";
				return;
			}
			else {
				cout << "Found nothing" << endl;
			}
		}
	}

};
