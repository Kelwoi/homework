#pragma once
#include "TV.h"
class TV;
class Remote {
private:
	TV* tv = nullptr;
public:

void chooseTV(TV * tv);

Remote(TV * tv = nullptr);

void power() const;

void operator +() const;
void operator -() const;
void operator ++() const;
void operator --() const;
void goChannel(const int& value);
friend class TV;
};