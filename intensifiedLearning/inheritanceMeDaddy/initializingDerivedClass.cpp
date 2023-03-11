#include <iostream>

// c++ prevents derived classes from initializing the member variables of the parent class
// it's because of the const and reference variables

class Base {

private:
    int m_baseInt{};
    int m_anotherBaseInt{};

public:
    Base(int baseInt, int anotherBaseInt)
        : m_baseInt{baseInt}, m_anotherBaseInt{anotherBaseInt} {
        }

    int getInt() {
        return m_baseInt;
    }
};

class Derived : public Base {

private:
    int m_derivedInt{};

public:
    Derived(int derivedInt, int someInt)
        : Base{derivedInt, someInt}, m_derivedInt{derivedInt} {}

    // using access function gives me access to the member variables
    int inheritInt() {
        return getInt();
    }
};

int main() {
    Base base{1, 2};

    Derived derived{10, 20};
    std::cout << derived.inheritInt();
    return 0;
}
