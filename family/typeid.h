#pragma once
#include <iostream>


class Grandpa {
public:
    virtual void Sleep() {
        std::cout << "Grandpa is sleeping." << std::endl;
    }
    virtual void Walk() = 0;
};

class Daddy : public Grandpa {
public:
    virtual void Walk() override {
        std::cout << "Daddy is walking." << std::endl;
    }
};

class Son : public Daddy {
public:
    virtual void Walk() override {
        std::cout << "Son is walking." << std::endl;
    }

    virtual void Play() {
        std::cout << "Son is playing." << std::endl;
    }
};


void callMethods(Grandpa* arr[], int size) {
    for (int i = 0; i < size; ++i) {
        arr[i]->Sleep();


        if (typeid(*arr[i]) == typeid(Daddy) || typeid(*arr[i]) == typeid(Son)) {
            arr[i]->Walk();
        }

        if (typeid(*arr[i]) == typeid(Son)) {
            static_cast<Son*>(arr[i])->Play();
        }
    }
}