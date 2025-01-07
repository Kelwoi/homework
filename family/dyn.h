#pragma once
#include <iostream>
class Grandpa {
public:
    virtual void Sleep() {
        std::cout << "Grandpa is sleeping." << std::endl;
    }
    virtual void Walk() {

    }

    virtual void Play() {

    }
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

    virtual void Play() override {
        std::cout << "Son is playing." << std::endl;
    }
};


void callMethods(Grandpa* arr[], int size) {
    for (int i = 0; i < size; ++i) {
        arr[i]->Sleep();


        if (Daddy* daddy = dynamic_cast<Daddy*>(arr[i])) {
            daddy->Walk();
        }

        if (Son* son = dynamic_cast<Son*>(arr[i])) {
            son->Play();
        }
    }
}