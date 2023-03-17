#include <iostream>
// virtual func me daddy

class Base {
protected:
	int m_value;

public:
	Base(int value)
		: m_value{ value } {}

	virtual const char* getName() {
        return "Base";
    }

    virtual ~Base() {
        std::cout << "Deleting base() \n";
    }
};

class Derived : public Base
{
public:
	Derived(int value)
		: Base{ value } {}

	virtual const char* getName() {
        return "Derived";
    }

    virtual ~Derived() {
        std::cout << "Deleting derived() \n";
    }
};

int main() {
	auto* d{ new Derived(5) };
	Base* b{ d };
	std::cout << b -> getName() << '\n';
	delete b;

	return 0;
}
