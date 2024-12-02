
#include "Vector.h"
#include <iostream>
using namespace std;
Vector::Vector()
	:Vector(1)
{

}

Vector::Vector(const size_t& size)
	:size(size), capacity(size)
{
	this->arr = new int[this->size] {};
}

Vector::Vector(const size_t& size, const int& value)
	:Vector(size)
{
	for (size_t i = 0; i < this->size; i++)
	{
		arr[i] = value;
	}
}

Vector::~Vector()
{
	if (arr != nullptr)
		delete[] arr;
}

Vector::Vector(const Vector& other)
	:Vector(other.size)
{
	for (size_t i = 0; i < this->size; i++)
	{
		arr[i] = other.arr[i];
	}
}

Vector& Vector::operator=(const Vector& other)
{
	if (this->arr != nullptr)
		delete[] this->arr;
	this->size = other.size;
	this->capacity = this->size;
	this->arr = new int[this->size];
	for (size_t i = 0; i < this->size; i++)
	{
		arr[i] = other.arr[i];
	}
	return *this;
}

void Vector::print() const
{
	cout << "Array has size ==> " << size << "; capacity ==> " << capacity << "\n\t";
	for (size_t i = 0; i < size; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
}

int Vector::operator[](size_t index) const
{
	if (isValidIndex(index))
		return arr[index];
	cout << ">>>>>>>>>>>>> Error index (get) : " << index << endl;
	return INT_MIN;
}

int& Vector::operator[](size_t index)
{
	static int errVal;
	if (isValidIndex(index))
		return arr[index];
	cout << ">>>>>>>>>>>>> Error index (set) : " << index << endl;
	return errVal;
}

Vector Vector::operator+(Vector other) const
{
	int iter = 0;
	Vector result(this->size + other.size);
	if (this->size >= other.size) {
		for (size_t i = 0; i < this->size; i++)
		{
			result.arr[i] = this->arr[i];
		}
		for (size_t j = this->size; j < result.size; j++)
		{
			result.arr[j] = other.arr[iter];
			iter++;
		}
	}
	else if (this->size < other.size) {
		for (size_t i = 0; i < other.size; i++)
		{
			result.arr[i] = other.arr[i];

		}
		for (size_t j = other.size; j < result.size; j++)
		{
			result.arr[j] = this->arr[iter];
			iter++;


		}
	}
	result.capacity = this->size + other.size;
	return result;
}

Vector Vector::operator-(const Vector& other) const
{
	int unique_count = 0;
	bool space_enough = true;
	for (size_t i = 0; i < this->size; i++)
	{
		for (size_t j = 0; j < other.size; j++)
		{
			if (this->arr[i] == other.arr[j]) {
				unique_count++;
				i++;
				j = 0;
			}
		}
	}
	if (this->size - unique_count < 1) {
		space_enough = false;
	}

	if (space_enough) {
		bool same = false;
		Vector result(this->size - unique_count);
		for (size_t i = 0; i < result.size; i++)
		{
			for (size_t j = 0; j < this->size; j++)
			{
				for (size_t a = 0; a < other.size; a++)
				{
					if (this->arr[j] == other.arr[a]) {
						same = true;
					}
				}
				if (!same) {
					result.arr[i] = this->arr[j];
					i++;
				}
			}
		}
		return result;
	}
	
}

Vector Vector::operator*(const size_t& n) const
{
	Vector result(this->size);
	for (size_t i = 0; i < this->size; i++)
	{
		result.arr[i] = this->arr[i] * n;
	}
	return result;
}

Vector::operator char* () const
{
	char* res = new char[size];
	for (size_t i = 0; i < size; i++)
	{
		int n = arr[i];
		string N = to_string(n);
		char const  *P = N.c_str();
		res[i] = char(P);
	}
	return res;
	

}
void Vector::pushback(const int& value)
{
	Vector res(size + 1);
	for (size_t i = 0; i < size; i++)
	{
		res.arr[i] = arr[i];
		res.arr[size] = value;
	}
	if (this->arr != nullptr)
		delete[] this->arr;
	this->size = res.size;
	this->capacity = this->size;
	this->arr = new int[this->size + 1];
	for (size_t i = 0; i < size + 1; i++)
	{
		arr[i] = res.arr[i];
	}
	
}
void Vector::pushfront(const int& value)
{
	Vector res(size + 1);
	for (size_t i = 0; i < size; i++)
	{
		res.arr[i + 1] = arr[i];
		res.arr[0] = value;
	}
	if (this->arr != nullptr)
		delete[] this->arr;
	this->size = res.size;
	this->capacity = this->size;
	this->arr = new int[this->size + 1];
	for (size_t i = 0; i < size + 1; i++)
	{
		arr[i] = res.arr[i];
	}
}
void Vector::insert(const int& value, const size_t& index)
{
	Vector res(size + 1);
	for (size_t i = 0; i < size + 1; i++)
	{
		if (i < index) {
			res.arr[i] = arr[i];
		}
		else if (i == index) {
			res.arr[i] = value;
		}
		else if (i > index) {
			res.arr[i] = arr[i - 1];
		}
	}
	if (this->arr != nullptr)
		delete[] this->arr;
	this->size = res.size;
	this->capacity = this->size;
	this->arr = new int[this->size + 1];
	for (size_t i = 0; i < size + 1; i++)
	{
		arr[i] = res.arr[i];
	}
}
void Vector::popBack()
{
	Vector res(size - 1);
	for (size_t i = 0; i < size - 1; i++)
	{
		res.arr[i] = arr[i];
	}
	if (this->arr != nullptr)
		delete[] this->arr;
	this->size = res.size;
	this->capacity = this->size;
	this->arr = new int[this->size];
	for (size_t i = 0; i < size; i++)
	{
		arr[i] = res.arr[i];
	}
}
void Vector::popfront()
{
	Vector res(size - 1);
	for (size_t i = 0; i < size - 1; i++)
	{
		res.arr[i] = arr[i + 1];
	}
	if (this->arr != nullptr)
		delete[] this->arr;
	this->size = res.size;
	this->capacity = this->size;
	this->arr = new int[this->size];
	for (size_t i = 0; i < size + 1; i++)
	{
		arr[i] = res.arr[i];
	}
}
void Vector::remove(const size_t& index)
{
	Vector res(size - 1);
	for (size_t i = 0; i < size - 1; i++)
	{
		if (i < index) {
			res.arr[i] = arr[i];
		}
		else if (i >= index) {
			res.arr[i] = arr[i + 1];
		}

	}
	if (this->arr != nullptr)
		delete[] this->arr;
	this->size = res.size;
	this->capacity = this->size;
	this->arr = new int[this->size];
	for (size_t i = 0; i < size + 1; i++)
	{
		arr[i] = res.arr[i];
	}
}
Vector::operator int() const
{
	int res = 0;
	for (size_t i = 0; i < this->size; i++)
	{
		res += this->arr[i];
	}
	return res;
}





Vector Vector::operator()(size_t startIndex, size_t lastIndex) const
{
	if (startIndex > lastIndex)
		swap(startIndex, lastIndex);
	if (!isValidIndex(startIndex))
		return Vector(0);
	if (lastIndex >= size)
		lastIndex = size - 1;
	Vector tmp(lastIndex - startIndex + 1);
	for (size_t i = 0; i < tmp.size; i++)
	{
		tmp[i] = this->arr[i + startIndex];
	}
	return tmp;
}

int Vector::find(const int& value)
{
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == value) {
			return i;

		}
	}
	return -1;
}
