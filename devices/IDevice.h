#pragma once
class IDevice
{
public:
    virtual void power() = 0;
    virtual void plus() = 0;
    virtual void minus() = 0;
    virtual void next() = 0;
    virtual void prev() = 0;
    virtual void showInfo() const = 0;
    virtual ~IDevice() {}
};

