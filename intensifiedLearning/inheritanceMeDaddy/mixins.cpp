#include <iostream>
#include <string>

template <class Derived>
struct Base {
    void name() {
        (static_cast<Derived*>(this))->impl();
    }
};

struct D1 : public Base<D1> {
    void impl() {
        std::puts("D1::impl()");
    }
};

struct D2 : public Base<D2> {
    void impl() {
        std::puts("D2::impl()");
    }
};

void test()
{
    Base<D1> b1; b1.name();
    Base<D2> b2; b2.name();
    D1 d1; d1.name();
    D2 d2; d2.name();
}

int main() {
    test();
    return 0;
}
