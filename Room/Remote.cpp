#include "Remote.h"
#include "TV.h"
void Remote::chooseTV(TV* tv)

{


	this->tv = tv;

}


Remote::Remote(TV* tv)

{

	chooseTV(tv);

}

void Remote::power() const

{

	tv->power();

}


void Remote::operator+() const

{

	tv->incVolume();

}

void Remote::operator-() const
{
	tv->decVolume();
}

void Remote::operator++() const
{
	tv->nextChannel();
}

void Remote::operator--() const
{
	tv->prevChannel();
}

void Remote::goChannel(const int& value)
{
	if(value < tv->MAX_CHANNEL)
	tv->current_channel = value;
}
