#pragma once
#include <iostream>
using namespace std;
#include "IDevice.h"
class AirConditioner :
    public IDevice
{
public:
    enum Mode { COOL, HEAT, TURBO, SLEEP, OFF };

private:
    bool isOn;
    int temperature;
    Mode currentMode;
    const int minTemp;
    const int maxTemp;

public:
    AirConditioner() : isOn(false), temperature(22), currentMode(OFF), minTemp(16), maxTemp(25) {}

    void power() override {
        isOn = !isOn;
        currentMode = isOn ? COOL : OFF;
        cout << (isOn ? "AirConditioner is now ON." : "AirConditioner is now OFF.") << endl;
    }

    void plus() override {
        if (isOn && temperature < maxTemp) {
            temperature++;
            cout << "Temperature: " << temperature << "C" << endl;
        }
    }

    void minus() override {
        if (isOn && temperature > minTemp) {
            temperature--;
            cout << "Temperature: " << temperature << "C" << endl;
        }
    }

    void next() override {
        if (isOn) {
            currentMode = static_cast<Mode>((currentMode + 1) % 4);
            cout << "Mode: " << getModeName() << endl;
        }
    }

    void prev() override {
        if (isOn) {
            currentMode = static_cast<Mode>((currentMode + 3) % 4);
            cout << "Mode: " << getModeName() << endl;
        }
    }

    void showInfo() const override {
        cout << "AirConditioner is " << (isOn ? "ON" : "OFF")
            << ", Temperature: " << temperature << "C"
            << ", Mode: " << getModeName() << endl;
    }

private:
    string getModeName() const {
        switch (currentMode) {
        case COOL: return "COOL";
        case HEAT: return "HEAT";
        case TURBO: return "TURBO";
        case SLEEP: return "SLEEP";
        default: return "OFF";
        }
    }
};

