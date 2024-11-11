#pragma once
#include <iostream>
#include <cstring>
using namespace std;
class String {
private:
    char* str;
    size_t length;
    static int objectCount;

public:

    String() : String(80) {
    }


    String(size_t len) : length(len) {
        str = new char[length + 1];  
        str[0] = '\0';               
        objectCount++;               
    }


    String(const char* input) : length(strlen(input)) {
        str = new char[length + 1];
        copyStr(str, input);
        objectCount++;
    }


    ~String() {
        delete[] str;
        objectCount--; 
    }


    void input() {
        cout << "Enter a string: ";
        char buffer[256];
        cin.getline(buffer, 256);


        delete[] str;
        length = strlen(buffer);
        str = new char[length + 1];
        copyStr(str, buffer);
    }


    void output() const {
        cout << "String: " << str << std::endl;
    }


    static int getObjectCount() {
        return objectCount;
    }
private:
    void copyStr(char*& dest, const char* source)
    {
        if (dest != nullptr)
            delete[] dest;
        size_t size = strlen(source) + 1;
        dest = new char[size];
        strcpy_s(dest, size, source);
    }
};


int String::objectCount = 0;
