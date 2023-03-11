#include <iostream>
#include <string>

class Base {
private:
    int m_value{};

public:
    Base(int value)
        :m_value{value} {}

    void printValue() const{
        std::cout << m_value << '\n';
    }

    virtual ~Base() = default;
};

class Derived: public Base {
private:
    std::string m_name{};

public:
    Derived(int value, std::string name)
        :Base{value}, m_name{name} {}

    const std::string& getName() const {
        return m_name;
    }
};

Base* getBaseObject(bool derivedObject) {
    if(derivedObject)
        return new Derived{1, "kesavan"};
    else
        return new Base{2};
}

int main() {
    Derived d{1, "Orange"};
    Base& b{d};

    Derived& ref{dynamic_cast<Derived&>(b)};
    std::cout << ref.getName();
    return 0;
}
