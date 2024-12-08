#include <iostream>
#include "Remote.h"
#include "TV.h"
using namespace std;
int main()
{
	TV tv1(30, 20, false, 50, 50);

	tv1.power();

	tv1.printInfo();



	Remote remote(&tv1);

	+remote;

	tv1.printInfo(); 

	++remote;

	tv1.printInfo();


	TV tv2(5, 10);

	remote.chooseTV(&tv2);
	tv2.printInfo();
	remote.power();
	tv2.printInfo();
	+remote; 
	tv2.printInfo();
	remote.goChannel(1);
	tv2.printInfo();



}


