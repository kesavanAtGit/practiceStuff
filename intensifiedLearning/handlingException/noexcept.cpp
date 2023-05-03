#include <iostream>
#include <stdexcept>

class Object {
public:
    ~Object() {
        std::cout << "object class destructed \n";
    }
};

void thrower() {
    std::cout << "throwing exception \n";
    throw 1;
}

void pt() {
    std::cout << "pt (case): potentially throwing \n";
    Object object{};
    thrower();
    std::cout << "this never prints \n";
}

void nt() noexcept{
    std::cout << "nt (case): non-throwing \n";
    Object object{};
    thrower();
    std::cout << "this never prints \n";
}

void tester(int value) noexcept {
    std::cout << "tester (case): noexcept function\n";
    try {
        if(value == 1) {
            pt();
        }else {
            nt();
        }
    }catch(...) {
        std::cout << "caught an exception \n";
    }
}

// C++17 Does not allow dynamic exception specification
//int doSomething() throw(std::out_of_range, int*);
//int doSomething() throw(...);

int main() {
    tester(1);
    std::cout << "Test 1 successful \n";
    tester(2);
    std::cout << "Test 2 successful \n";
    return 0;
}
