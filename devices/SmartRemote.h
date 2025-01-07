#pragma once
#include <iostream>
using namespace std;
#include "IDevice.h"
class SmartRemote :
    public IDevice
{
private:
    IDevice* device;

public:
    SmartRemote() : device(nullptr) {}

    void setDevice(IDevice* newDevice) {
        device = newDevice;
        cout << "Device switched." << endl;
    }

    void power() {
        if (device) device->power();
    }

    void plus() {
        if (device) device->plus();
    }

    void minus() {
        if (device) device->minus();
    }

    void next() {
        if (device) device->next();
    }

    void prev() {
        if (device) device->prev();
    }

    void showInfo() const {
        if (device) device->showInfo();
        else cout << "No device connected." << endl;
    }
};

