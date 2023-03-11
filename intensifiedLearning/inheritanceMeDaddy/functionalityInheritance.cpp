#include <iostream>

class Base {

protected:
    int m_protected{};

    void sayProtected() {
        std::cout << "I'm protected Baby \n";
    }

public:
    int m_public{};

    Base(int protectedVar)
        : m_protected{protectedVar} {}

    void printState() {
        std::cout << "I'm private \n";
    }

    void print() {
        std::cout << "BASE \n";
    }

    friend std::ostream& operator<< (std::ostream& out, const Base& base) {
        out << base.m_protected;
        return out;
    };
};

class Derived : public Base {

public:

    Derived(int protectedVar)
        : Base{protectedVar} {}

    int getValue() const{return m_protected;}

    friend std::ostream& operator<< (std::ostream& out, const Derived& derived) {
        out << "In the derived class \n";
        out << static_cast<const Base&>(derived);
        return out;
    };

    using Base::sayProtected;
    // can't now use this deleted function
    void printState() = delete;

};

int main() {

    Derived derived{10};
    Base& base{static_cast<Base&>(derived)};
    std::cout << base;

    return 0;
}
