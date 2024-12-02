#include <iostream>
#include "Vector.h"
using namespace std;
int main()
{
	Vector test(10, 3);
	Vector test2(10, 4);
	Vector test3(10, 4);
	Vector test_test = test + test2;
	test_test.print();
	Vector test_test_test = test2 - test;
	test_test_test.print();
	Vector res = test * 2;
	res.print();
	cout << int(test);
	test2.pushfront(2);
	test2.print();
	test2.popfront();
	test2.print();
	test2.insert(3, 3);
	test2.print();
	test2.remove(3);
	test2.print();
	test2.insert(3, 4);
	cout << test2.find(3);

}