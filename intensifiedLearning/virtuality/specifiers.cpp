#include <iostream>

// we're going to see about the two identifiers used in inheritance
// override and final

class Base {
public:
    virtual Base* getSomething() {std::cout << "called Base::getSomething() \n"; return this;}
    void printType() {std::cout << "base";}
};

class Derived : public Base {
public:
    Derived* getSomething() override {std::cout << "called Derived::getSomething() \n"; return this;}
    void printType() {std::cout << "Derived \n";}
};

int main() {
    Derived derived{};
    Base* ref{&derived};

    derived.getSomething() -> printType();
    ref -> getSomething() -> printType();

    return 0;
}
