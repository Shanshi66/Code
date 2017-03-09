#pragma once

class Singleton {
public:
    Singleton getInstance(){
        if (singleton == nullptr) {
            singleton = new Singleton();
        }
        return *singleton;
    }
private:
    Singleton(){}
    static Singleton *singleton;
};

Singleton Singleton::*singleton = nullptr;