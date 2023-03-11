#include <iostream>
#include <string>
#include <vector>

class Base {
private:
    int m_value{};
public:
    Base(int value)
        :m_value{value} {}

    virtual void printSomething() const {
        std::cout << "In base \n";
    }

    int getValue() const {return m_value;}
};

class Derived : public Base {
public:
    Derived(int value)
        :Base{value} {}

    void printSomething() const override{
        std::cout << "In derived \n";
    }
};

void printClassName(const Base& base) {
    base.printSomething();
}

int main() {
    Derived d{10};

    // slicing happens here
    Base base{d};
    return 0;
}
