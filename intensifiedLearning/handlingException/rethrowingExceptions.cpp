#include <iostream>
#include <string>
#include <cassert>

class Base {
    public:
        Base() {}
        virtual void print() {std::cout << "this is base \n";}
};

class Derived : public Base{
    public:
        Derived() {}
        void print() override{std::cout << "this is derived \n";}
};

int* returnPtr(int* ptr) {
    try {
        ptr = new int[5];
        throw ptr;
    }catch(int*) {
        delete ptr;
        //g_log.logError("something wrong with the memory allocation");
        // throwing a char type to be handled by the caller up the stack
        throw 'k';
    }
}

int main() {
    try {
        try {
            throw Derived{};
        }catch(Base& base) {
            base.print();
            // this ackshually throws the same object no copies or slicing made here
            throw;
        }
    }catch (Base& base) {
        base.print();
    }
    return 0;
}
