#include "TV.h"
#include <iostream>
using namespace std;
TV::TV(const int& current_volume, const int& current_channel,const bool& offon, const int& MAX_CHANNEL, const int& MAX_VOLUME)
	: current_volume{current_volume},current_channel{current_channel},OFFON{offon},MAX_CHANNEL{MAX_CHANNEL},MAX_VOLUME{MAX_VOLUME}
{
}

void TV::incVolume()
{
	if (current_volume + 1 < MAX_VOLUME and OFFON == true)
		current_volume++;
}

 void TV::decVolume()
{
	if (current_volume - 1 < 0 and OFFON == true)
		current_volume--;
}

 void TV::nextChannel()
{
	 if (current_channel + 1 > MAX_CHANNEL)
		 current_channel = 1;
	if (current_channel + 1 < MAX_CHANNEL and OFFON == true)
		current_channel++;
}

 void TV::prevChannel()
{
	 if (current_channel - 1 < 1)
		 current_channel = MAX_CHANNEL;
	if (current_channel - 1 < 0 and OFFON == true)
		current_channel--;
}

 void TV::power()
{

	if (OFFON == false)
		OFFON = true;
	else
		OFFON = false;
}

void TV::printInfo() const
{
	cout << "TV ";
	if (OFFON == true)
		cout << "ON";
	else
		cout << "off";
	cout << " Active channel: " << current_channel << " volume: " << current_volume;
	cout << endl;
}
