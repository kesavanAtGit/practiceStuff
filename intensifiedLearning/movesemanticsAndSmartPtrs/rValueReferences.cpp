#include <iostream>

void printInt(const int& lref) {
    std::cout << lref << '\n';
}

void printInt(int&& rref) {
    std::cout << rref << '\n';
}

class Fraction {
private:
    int m_numerator{};
    int m_denominator{};

public:
    Fraction(int numerator, int denominator)
        :m_numerator{numerator}, m_denominator{denominator} {}

    friend std::ostream& operator<<(std::ostream& out, const Fraction& fraction) {
        out << fraction.m_numerator << " / " << fraction.m_denominator;
        return out;
    }
};

int main() {
    int x{10};
    printInt(x);
    printInt(12);
    return 0;
}
