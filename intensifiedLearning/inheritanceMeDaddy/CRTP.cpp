#include <cstdio>
#include <iostream>

template <class Derived>
class Base {
 public:
     void printName() {
         static_cast<Derived*>(this) -> name();
     }
};

class Derived: public Base<Derived> {
public:
    void name() {
        std::puts("oh yes, the name");
    }
};

void test() {
    Base<Derived> one{};
    one.printName();
    Derived d1{}; d1.name();
    Derived d2{}; d1.name();
}

int main() {
    test();
    return 0;
}
