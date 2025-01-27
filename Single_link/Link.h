#pragma once
#include <iostream>
using std::cout;
using std::endl;
template<typename T>
struct Node
{
	T data;
	Node* next;
	Node(const T& data = T(), Node* next = nullptr)
		:data(data), next(next) {}
};
template<typename T>
class FwdList
{
public:
	FwdList() = default;
	bool empty() const;
	void print() const;

	void addHead(const T& data);
	void removeHead();
	void addTail(const T& data);

	FwdList<T> operator*(const FwdList<T>& other) const;
	FwdList<T> operator+(const FwdList<T>& other) const;
	FwdList<T> Clone() const;
private:
	Node<T>* head = nullptr;
	Node<T>* tail = nullptr;
	size_t size = 0;
};

template<typename T>
inline bool FwdList<T>::empty() const
{
	return head == nullptr;
}

template<typename T>
inline void FwdList<T>::print() const
{
	if (empty()) {
		cout << "List is empty" << endl;
		return;
	}
	auto tmp = head;
	cout << "List :\t";
	while (tmp != nullptr) 
	{
		cout << tmp->data << "\t";
		tmp = tmp->next; 
	}
	cout << endl;
}

template<typename T>
inline void FwdList<T>::addHead(const T& data)
{
	Node<T>* tmp = new Node<T>(data, head);
	if (empty())
		tail = tmp;
	head = tmp;
	++size;
}

template<typename T>
inline void FwdList<T>::removeHead()
{
	if (empty())
		return;
	auto tmp = head;
	head = head->next;
	if (empty())
		tail = head;
	delete tmp;
	--size;
}

template<typename T>
inline void FwdList<T>::addTail(const T& data)
{
	auto tmp = new Node<T>(data);
	if (!empty())
		tail->next = tmp;

	if (empty())
		head = tmp;
	tail = tmp;
	++size;
}

template<typename T>
inline FwdList<T> FwdList<T>::operator*(const FwdList<T>& other) const
{
	FwdList<T> result;
	auto tmp = head;
	while (tmp != nullptr)
	{
		auto other_tmp = other.head;
		while (other_tmp != nullptr)
		{
			if (tmp->data == other_tmp->data) {
				result.addTail(tmp->data);
				break;
			}
			other_tmp = other_tmp->next;
		}
		tmp = tmp->next;
	}
	return result;
}
template<typename T>
inline FwdList<T> FwdList<T>::operator+(const FwdList<T>& other) const
{
	FwdList<T> result = this->Clone();
	auto tmp = other.head;

	while (tmp != nullptr)
	{
		result.addTail(tmp->data);
		tmp = tmp->next;
	}
	return result;
}
template<typename T>
inline FwdList<T> FwdList<T>::Clone() const
{
	FwdList<T> clonedList;
	auto tmp = head;
	while (tmp != nullptr)
	{
		clonedList.addTail(tmp->data);
		tmp = tmp->next;
	}
	return clonedList;
}