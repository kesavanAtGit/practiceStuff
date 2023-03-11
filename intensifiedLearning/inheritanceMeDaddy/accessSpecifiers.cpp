#include <iostream>

class Base{

private:
    int m_priBase{}; // only in the base class

protected:
    int m_proBase{}; // only by its members, friends and the derived classes

public:
    int m_anotherPubBase{};
    int m_pubBase{}; // anywhere

    void printSomething() {
        std::cout << "something \n";
    }
};

class Derived : protected Base {
    public:
        void print() {
            std::cout << m_proBase << " " << m_pubBase << '\n';
            printSomething();
        }
};

class Pri : private Base {
public:
    void comeOn() {
        m_pubBase = 10;
        m_proBase = 20;
        std::cout << m_pubBase << " " << m_proBase << '\n';
    }
};

int main() {
    Pri privateDaddy{};
    privateDaddy.comeOn();

    return 0;
}
