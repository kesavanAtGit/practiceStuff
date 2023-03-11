#include <iostream>
#include <string>

// Functions that resolve to the most-derived version of the function that exists between a base
// class and a derived class
// This capability is called polymorphism
// remember the override thing(the name, parameter types and the return type should match between the functions)

class Base {
public:
    virtual std::string getName() const{return "base";}
};

class Derived: public Base {
public:
    virtual std::string getName() const{return "derived";}
};

class A {
public:
    virtual int returnValue() const{return 10;}
};

class B: public A {
public:
    virtual int returnValue() const{return 20;}
};

class C: public B {
public:
    virtual int returnValue() const{return 30;}
};

int main() {
    C c{};
    A& ref{c};

    std::cout << ref.returnValue();
    return 0;
}
