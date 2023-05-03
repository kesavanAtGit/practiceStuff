#include <iostream>
#include <memory>
#include <utility>

class Something {
public:
    Something() {std::cout << "something is created \n";}
    ~Something() {std::cout << "something is destroyed \n";}
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

    void saySomething() {
        std::cout << "something \n";
    }
};

int main() {
    auto sharedPtr{std::make_shared<Something>()};
    {
        auto anotherSharedPtr{sharedPtr};
        std::cout << "killing anotherSharedPtr \n";
    }
    std::cout << "killing sharedPtr \n";
    return 0;
}
