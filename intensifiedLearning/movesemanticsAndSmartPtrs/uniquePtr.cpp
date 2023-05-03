#include <iostream>
#include <memory>
#include <utility>

// unique point me daddy
// std::unique_ptr is smart enough to use scalar delete and array delete
// so don't have to worry about that

class Something {
public:
    Something() {std::cout << "something is constructed \n";}
    ~Something() {std::cout << "something is destructed \n";}

    friend std::ostream& operator<< (std::ostream& out, const Something& something) {
        out << "I am a something resource";
        return out;
    }
};

class Fraction {
private:
    int m_numerator{};
    int m_denominator{};

public:
    Fraction(int numerator=0, int denominator=1)
        :m_numerator(numerator), m_denominator(denominator) {}

    friend std::ostream& operator<< (std::ostream& out, const Fraction& fraction) {
        out << fraction.m_numerator << "/" << fraction.m_denominator;
        return out;
    }
};

void doSomething(Fraction* fraction) {
    if(fraction) {
        std::cout << *fraction;
    }
    else {
        std::cout << "I am fucking nulled \n";
    }
}

void something(std::unique_ptr<Fraction> fraction) {
    if(fraction) {
        std::cout << *fraction;
    }
    else {
        std::cout << "I am fucking nulled \n";
    }
}


// returning a std::unique_ptr from a function
std::unique_ptr<Something> createSomething() {
    auto something{std::make_unique<Something>()};
    return something;
}

int main() {
    // use std::make_unique templated function instead of creating a std::unique_ptr yourself
    auto fracMeDaddy{std::make_unique<Fraction>(1,4)};
    // using get() to get the pointer of the fraction resource
    // move me daddy since copy semantics for a unique_ptr are disabled
    something(std::move(fracMeDaddy));
    return 0;
}
