#pragma once

#include "HotDrink.h"

class Coffee : public HotDrink {
public:
    Coffee() : HotDrink("coffee", 200, 10, 2) {}
};


