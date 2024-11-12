#include <iostream>
#include "Cat.h"
#include "Dog.h"
#include "Parrot.h"
int main() 

{
	Cat cat("barsil", 3, "blue", "yellow", 12);
	Cat catcat("Kuzia", 12, "Grey", "British", 20);
	cat.print();
	catcat.print();
	cat.meow();
	Dog dog("sharik", 5, "grey", "dvorniaga", 59);
	dog.print();
	Parrot parrot("kesha", 4, "blue", "yellow", "light-blue");
	parrot.print();

}


