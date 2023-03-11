#include <iostream>

class Base {
    public:
        int m_baseInt{};
        int m_anotherBaseInt{};

        Base(int baseInt = 0, int anotherBaseInt = 0)
            : m_baseInt{baseInt}, m_anotherBaseInt{anotherBaseInt} {
                std::cout << "Constructing base \n";
            }

        int getInts() {
            return m_baseInt;
        }
};

class Derived : public Base {
    public:
        int m_derivedInt{};

        Derived(int derivedInt = 0): m_derivedInt{derivedInt} {
            std::cout << "Constructing derived \n";
        }
};

int main() {
    std::cout << "Base me daddy \n";
    Base base;

    std::cout << "Derive me daddy \n";
    Derived derived;
    return 0;
}
