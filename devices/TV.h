#pragma once
#include <iostream>
#include "IDevice.h"
using namespace std;
class TV : public IDevice
{
private:
    bool isOn;
    int volume;
    int channel;
    const int maxVolume;
    const int maxChannels;

public:
    TV() : isOn(false), volume(10), channel(1), maxVolume(100), maxChannels(50) {}

    void power() override {
        isOn = !isOn;
        cout << (isOn ? "TV is now ON." : "TV is now OFF.") << endl;
    }

    void plus() override {
        if (isOn && volume < maxVolume) {
            volume++;
            cout << "Volume: " << volume << endl;
        }
    }

    void minus() override {
        if (isOn && volume > 0) {
            volume--;
           cout << "Volume: " << volume << endl;
        }
    }

    void next() override {
        if (isOn) {
            channel = (channel % maxChannels) + 1;
            cout << "Channel: " << channel << endl;
        }
    }

    void prev() override {
        if (isOn) {
            channel = (channel == 1) ? maxChannels : channel - 1;
            cout << "Channel: " << channel << endl;
        }
    }

    void showInfo() const override {
        cout << "TV is " << (isOn ? "ON" : "OFF")
            << ", Volume: " << volume
            << ", Channel: " << channel << endl;
    }
};

