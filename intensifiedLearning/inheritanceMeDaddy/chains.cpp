#include <iostream>

// chain me daddy
class A{
public:
    A(int a) {
        std::cout << "A is " << a << '\n';
    }
};

class B: public A {
public:
    B(int a, double b): A{a} {
        std::cout << "B is " << b << '\n';
    }
};

class C: public B {
public:
    C(int a, double b, char c): B{a, b} {
        std::cout << "C is " << c << '\n';
    }
};

int main() {
    C cee {10, 34.34, 'c'};
    return 0;
}
