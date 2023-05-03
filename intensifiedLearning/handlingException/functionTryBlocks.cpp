#include <iostream>

class A {
private:
    int m_value{};

public:
    A(int value) : m_value{value} {
        if(value <= 0)
            throw -1;
    }
};

class B : public A{
public:
    B(int value) try : A{value} {
    }catch(...) {
        std::cout << "caught an exception \n";
        // explicitly done to not let the program reach the end of the catch block which would implicitly rethrow
        throw;
    }
};

int main() {
    try {
        B b{0};
    }catch(int exception) {
        std::cout << "oopsy daisy \n";
    }
    return 0;
}
