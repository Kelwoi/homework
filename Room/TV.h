#pragma once
#include "Remote.h"
class Remote;
class TV {
private:
	bool OFFON = false;
	int current_volume = 0;
	int current_channel = 0;
	const int MAX_CHANNEL = 100;
	const int MAX_VOLUME = 100;
public:
	TV() = default;
	TV(const int& current_volume = 1, const int& current_channel = 1, const bool& offon = false, const int& MAX_CHANNEL = 100, const int& MAX_VOLUME = 100);
	void incVolume();
	void decVolume();
	void nextChannel();
	void prevChannel();
	void power();
	void printInfo() const;
	friend class Remote;
};