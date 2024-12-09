#pragma once
#include <iostream>
using namespace std;
template <typename T = int>
class Array {
public:
	Array() = default;
	Array(const size_t size,const size_t capacity);
	void print() const;
	int GetSize() const;
	void SetSize(int newsize, int grow = 1) ;
	int  GetUpperBound() const;
	void IsEmpty();
	void FreeExtra();
	T GetAt(const int& index);
	void SetAt(const int& index, const T& value);
	void InsertAt(const int& index, const T& value);
	void RemoveAt(const int& index);
	T& operator[](size_t index);
	const T& operator[](size_t index) const;
	void Add(const T& element);
	void Append(const Array<T>& other);
	T* GetData();

private:
	size_t size = 0;
	size_t capacity = 0;
	T* arr = nullptr;
};

template<typename T>
inline Array<T>::Array(const size_t size, const size_t capacity)
	:size{size},capacity{capacity}
{
	arr = new T[capacity];
	for (size_t i = 0; i < size; i++) {
		arr[i] = T();
	}
}
template<typename T>
void Array<T>::FreeExtra() {
	if (capacity > size) {
		T* newArr = new T[size];
		for (size_t i = 0; i < size; i++) {
			newArr[i] = arr[i];
		}
		delete[] arr;
		arr = newArr;
		capacity = size;
	}
}
template<typename T>
inline T Array<T>::GetAt(const int& index)
{
	if (index < size) {
		return arr[index];
	}

}
template<typename T>
inline void Array<T>::SetAt(const int& index, const T& value)
{
	if (index < size) {
		arr[index] = value;
	}
}
template<typename T>
inline void Array<T>::InsertAt(const int& index, const T& value)
{
	T* arr2 = new T[size + 1];
	for (size_t i = 0; i < size + 1; i++)
	{
		if (i < index) {
			arr2[i] = arr[i];
		}
		if (i == index) {
			arr2[i] = value;
		}
		if (i > index) {
			arr2[i] = arr[i - 1];
		}
	}
	size++;


	delete[] arr;
	arr = arr2;
}
template<typename T>
inline void Array<T>::RemoveAt(const int& index)
{
	T* arr2 = new T[size - 1];
	for (size_t i = 0; i < size; i++)
	{
		if (i < index) {
			arr2[i] = arr[i];
		}
		if (i >= index) {
			arr2[i] = arr[i + 1];
		}

	}
	delete[] arr;
	arr = arr2;
	size--;
}
template<typename T>
void Array<T>::print() const {
	for (size_t i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << "\nSize: " << size << ", Capacity: " << capacity << endl;
}

template<typename T>
inline int Array<T>::GetSize() const
{
	return capacity;
}

template<typename T>
inline void Array<T>::SetSize(int newsize, int grow)
{
	if (this->size < newsize) {
		int newCapacity = (newsize / grow + 1) * grow;
		T* newArr = new T[newCapacity];
		for (size_t i = 0; i < newsize; i++)
		{
			newArr[i] = T();
		}
		delete[] arr;
		arr = newArr;
		size = newsize;
		capacity = newCapacity;
	}
}

template<typename T>
inline int Array<T>::GetUpperBound() const
{
	return size - 1;
}

template<typename T>
inline void Array<T>::IsEmpty()
{
	bool empty = true;
	for (size_t i = 0; i < size; i++)
	{
		if (arr[i] != T()) {
			cout << "Massive is't empty";
			empty = false;
		}

	}
	if (empty) {
		cout << "Massive is empty";
	}

}
template <typename T>
T& Array<T>::operator[](size_t index) {

	if (index >= size) {
		return 0;
	}
	return arr[index];
}
template <typename T>
const T& Array<T>::operator[](size_t index) const {
	if (index >= size) {
		return 0;
	}
	return arr[index];
}
template <typename T>
void Array<T>::Add(const T& element) {

	if (size >= capacity) {

		SetSize(size + 1);
	}


	arr[size] = element;
	size++; 
}

template <typename T>
void Array<T>::Append(const Array<T>& other) {

	if (size + other.size > capacity) {
		SetSize(size + other.size);
	}


	for (size_t i = 0; i < other.size; i++) {
		arr[size] = other.arr[i];
		size++;
	}
}
template <typename T>
T* Array<T>::GetData() {
	return arr;
}