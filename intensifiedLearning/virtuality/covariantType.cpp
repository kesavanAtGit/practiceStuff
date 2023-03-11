#include <iostream>

// covariant return types
class A {
public:

    void print() {
        std::cout << "printing in A \n";
    }

    virtual void printSomething() {
        std::cout << "something in A \n";
    }
};

class B: public A {
public:

    void print() {
        std::cout << "printing in B \n";
    }
    void printSomething() override{
        std::cout << "something in B \n";
    }
};

class C {

private:
    A m_a{};

public:
    virtual A& doSomething() {
        return m_a;
    }
};

class D: public C {

private:
    B m_b{};

public:
    B& doSomething() override{
        return m_b;
    }
};

int main() {
    D dClass{};
    dClass.doSomething().print();
    dClass.doSomething().printSomething();

    std::cout << '\n';

    C cClass{};
    cClass.doSomething().print();
    cClass.doSomething().printSomething();

    std::cout << '\n';

    C& ref{dClass};
    ref.doSomething().print();
    ref.doSomething().printSomething();
    return 0;
}
