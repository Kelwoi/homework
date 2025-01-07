
#include <iostream>
#include "TV.h"
#include "AirConditioner.h"
#include "SmartRemote.h"
int main()
{
    TV tv;
    AirConditioner ac;
    SmartRemote remote;


    remote.setDevice(&tv);
    remote.showInfo();
    remote.power();
    remote.plus();
    remote.next();
    remote.showInfo();


    remote.setDevice(&ac);
    remote.showInfo();
    remote.power();
    remote.plus();
    remote.next();
    remote.showInfo();
}


