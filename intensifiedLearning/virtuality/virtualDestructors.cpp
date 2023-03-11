#include <iostream>

class Base {

public:
    virtual ~Base() {
        std::cout << "deleting base() \n";
    }

    virtual void printSomething() {
        std::cout << "Base \n";
    }
};

class Derived: public Base {

private:
    int* m_array{};

public:
    Derived(int length)
        :m_array{new int[length]} {}

    virtual void printSomething() {
        std::cout << "Derived \n";
    }

    virtual ~Derived() {
        std::cout << "deleting derived() \n";
        delete[] m_array;
    }
};

int main() {
    Derived* derived{new Derived(5)};
    Base* base{derived};

    //base->Base::printSomething();
    //base->printSomething();

    delete base;
    return 0;
}

