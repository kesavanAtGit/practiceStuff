#include <iostream>

// The transfer of ownership of a class object rather than making a copy is called move semantics.

template <typename T>
class Something {
private:
    T* m_ptr{};

public:
    Something(T* ptr=nullptr)
        : m_ptr{ptr} {}

    ~Something() {
        delete m_ptr;
    }

    // copy constructor
    Something(Something& something) {
        m_ptr = something.m_ptr;
        something.m_ptr = nullptr;
    }

    // overloading the assignment operator
    Something& operator=(Something& anotherSomething) {
        if(&anotherSomething == this)
            return *this;

        delete m_ptr;
        m_ptr = anotherSomething.m_ptr;
        anotherSomething.m_ptr = nullptr;
        return *this;
    }

    // overloading the dereference and the arrow operator
    T& operator* () const{return *m_ptr;}
    T* operator-> () const{return m_ptr;}
    bool isNull() {return m_ptr == nullptr;}
};

class Code {
public:
    Code() {std::cout << "code class constructed \n";}
    ~Code() {std::cout << "code class destructed \n";}
    void sayBaka() {std::cout << "baka \n";}
};

void something() {
    // foo here is a smart pointer class object
    Something<Code> foo{new Code{}};
    std::cout << "Enter an integer: \n";
    int x{};
    std::cin >> x;

    if(x == 0)
        return;

    foo->sayBaka();
}

int main() {
    Something<Code> foo{new Code{}};
    Something<Code> boo;

    std::cout << "foo is " << (foo.isNull() ? "null" : "not null") << '\n';
    std::cout << "boo is " << (boo.isNull() ? "null" : "not null") << '\n';

    boo = foo;
    std::cout << "ownership transferred to boo \n";

    std::cout << "foo is " << (foo.isNull() ? "null" : "not null") << '\n';
    std::cout << "boo is " << (boo.isNull() ? "null" : "not null") << '\n';
    return 0;
}
