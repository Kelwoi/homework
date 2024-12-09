
#include <iostream>
#include "array.h"
int main()
{
	Array<int> m(3, 5);
	m.print();
	m.FreeExtra();
	m.print();
	m.SetSize(16, 5);
	m.print();
	m.IsEmpty();
	cout << m.GetAt(2);
	m.SetAt(2, 3);
	m.print();
	Array<char>e(3, 5);
	e.print();
	e.SetAt(2, 'f');
	e.print();
	m.InsertAt(2, 4);
	m.print();
	m.RemoveAt(2);
	m.print();
	m.Add(1);
	m.print();
}


