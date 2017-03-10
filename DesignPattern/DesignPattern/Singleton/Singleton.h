#pragma once
#include "../utils.h"

namespace Single{
    mutex singleMutex;
    class Singleton1 {
    public:
        static Singleton1* getInstance() {
            if (singleton == nullptr) {
                Single::singleMutex.lock();
                if (singleton == nullptr) {
                    singleton = new Singleton1();
                    singleMutex.unlock();
                }
            }
            return singleton;
        }
    private:
        Singleton1() {
            cout << "Create Instance..\n" << endl;
        }
        static Singleton1 *singleton;
    };
    Singleton1* Singleton1::singleton = nullptr;

    class Singleton2 {
    public:
        static Singleton2* getInstance() {
            return singleton;
        }
    private:
        Singleton2() {
            cout << "Create Instance..\n" << endl;
        }
        static Singleton2 *singleton;
    };
    Singleton2* Singleton2::singleton = new Singleton2();
}