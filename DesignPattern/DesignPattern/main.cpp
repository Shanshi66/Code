#include "utils.h"
#include "Singleton/Singleton.h"

using namespace std;
using namespace Single;

void createInstance() {
    Singleton2 *instance = Singleton2::getInstance();
}

int main() {
    thread t(createInstance);
    Singleton2 *instance = Singleton2::getInstance();
    t.join();
    getchar();
    return 0;
}