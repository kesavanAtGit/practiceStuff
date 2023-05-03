#include <iostream>
#include <stdexcept>
#include <exception>

class Fraction {
private:
    int m_numerator{};
    int m_denominator{};

public:
    Fraction(int numerator, int denominator)
        :m_numerator{numerator}, m_denominator{denominator} {
            if(denominator == 0) {
                throw std::runtime_error{"invalid denominator"};
            }
        }

    friend std::ostream& operator<<(std::ostream& out, const Fraction& fraction) {
        out << fraction.m_numerator << " / " << fraction.m_denominator;
        return out;
    }

    //void print() {
    //    std::cout << m_numerator << " / " << m_denominator << '\n';
    //}
};

int main() {
    std::cout << "Enter the numerator: ";
    int numerator{};
    std::cin >> numerator;

    std::cout << "Enter the denominator: ";
    int denominator{};
    std::cin >> denominator;

    try {
        Fraction fraction{numerator, denominator};
        std::cout << fraction;
        //fraction.print();
    }catch(const std::runtime_error& exception) {
        std::cout << exception.what();
    }
    return 0;
}
