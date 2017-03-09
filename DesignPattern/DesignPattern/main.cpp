#include <iostream>
#include "Singleton/SingletonMutithread.h"

int main() {
    Singleton a = Singleton::getInstance();
    getchar();
    return 0;
}