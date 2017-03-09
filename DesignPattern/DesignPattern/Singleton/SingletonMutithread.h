#pragma once
#include "../utils.h"

class Singleton {
public:
    static Singleton getInstance() {
        return singleton;
    }
private:
    Singleton() {
        cout << "Yes" << endl;
    }
    static Singleton singleton;
};

Singleton Singleton::singleton = Singleton();