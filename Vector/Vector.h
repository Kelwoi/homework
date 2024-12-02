#pragma once
#include <string>
class Vector
{
public:
	Vector();
	Vector(const size_t& size);
	Vector(const size_t& size, const int& value);
	~Vector();
	Vector(const Vector& other);
	Vector& operator =  (const Vector& other);

	const size_t& getSize() const { return this->size; }
	const size_t& getCapacity() const { return this->capacity; }
	void print() const;
	int operator[](size_t index) const;//get
	int& operator[](size_t index) ; //set
	Vector operator+(Vector other) const;
	Vector operator- (const Vector& other) const;
	Vector operator * (const size_t& n) const;
	explicit operator char* () const;
	explicit operator int() const;
	void pushback(const int& value);
	void pushfront(const int& value);
	void insert(const int& value, const size_t& index);
	void popBack();
	void popfront();
	void remove(const size_t& index);
	Vector operator()(size_t startIndex, size_t lastIndex) const;
	int find(const int& value);
private:

	int* arr = nullptr;
	size_t size = 0;
	size_t capacity = 0;
	bool isValidIndex(size_t index) const;
};
inline bool Vector::isValidIndex(size_t index) const
{
	return index < size;
}