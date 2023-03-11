#include <ios>
#include <iostream>
#include <cstdint>
#include <cmath>
#include <iomanip>

class FixedPoint2 {
private:
    std::int16_t m_decimalPart{};
    std::int16_t m_fractionalPart{}; // this number should hold only 2 digits

public:

    FixedPoint2(std::int16_t decimal, std::int16_t fraction):
        m_decimalPart{decimal}, m_fractionalPart{fraction} {

            if(m_fractionalPart > 99 || m_fractionalPart < -99) {
                m_fractionalPart /= 100;
            }

            if(m_decimalPart < 0 || m_fractionalPart < 0) {
                if(m_decimalPart > 0)
                    m_decimalPart = -m_decimalPart;
                if(m_fractionalPart > 0)
                    m_fractionalPart = -m_fractionalPart;
            }
        }

    FixedPoint2(double fixedPoint)

        : m_decimalPart{static_cast<std::int16_t>(std::trunc(fixedPoint))},
          m_fractionalPart{static_cast<std::int16_t>(std::round(fixedPoint * 100) - m_decimalPart * 100)} {}

    friend FixedPoint2 operator+ (const FixedPoint2& fp1, const FixedPoint2 fp2) {
        return {static_cast<double>(fp1) + static_cast<double>(fp2)};
    }

    FixedPoint2 operator- () {
        return {static_cast<std::int16_t>(-m_decimalPart), static_cast<std::int16_t>(-m_fractionalPart)};
    }

    friend bool operator== (const FixedPoint2& fixedPoint, const FixedPoint2& fixedPoint1) {
        return ( fixedPoint.m_decimalPart == fixedPoint1.m_decimalPart && fixedPoint.m_fractionalPart == fixedPoint1.m_fractionalPart);
    }

    // typecasting the object into a double
    operator double() const{
        return m_decimalPart + (static_cast<double>(m_fractionalPart) / 100);
    }

    friend std::ostream& operator<< (std::ostream& out, const FixedPoint2& fixedPoint);
    friend std::istream& operator>> (std::istream& in, FixedPoint2& fixedPoint);
};

std::ostream& operator<< (std::ostream& out, const FixedPoint2& fixedPoint) {
    out << static_cast<double>(fixedPoint);
    return out;
}

std::istream& operator>> (std::istream& in, FixedPoint2& fp) {
    double d{};
    in >> d;
    fp = FixedPoint2{d};
    return in;
}

void testAddition() {

	std::cout << std::boolalpha;

    std::cout << (FixedPoint2{ 0.75 } + FixedPoint2{ 1.23 } == FixedPoint2{ 1.98 }) << '\n';
    std::cout << (FixedPoint2{ 0.75 } + FixedPoint2{ 1.50 } == FixedPoint2{ 2.25 }) << '\n';
    std::cout << (FixedPoint2{ -0.75 } + FixedPoint2{ -1.23 } == FixedPoint2{ -1.98 }) << '\n';
    std::cout << (FixedPoint2{ -0.75 } + FixedPoint2{ -1.50 } == FixedPoint2{ -2.25 }) << '\n';
    std::cout << (FixedPoint2{ 0.75 } + FixedPoint2{ -1.23 } == FixedPoint2{ -0.48 }) << '\n';
    std::cout << (FixedPoint2{ 0.75 } + FixedPoint2{ -1.50 } == FixedPoint2{ -0.75 }) << '\n';
    std::cout << (FixedPoint2{ -0.75 } + FixedPoint2{ 1.23 } == FixedPoint2{ 0.48 }) << '\n';
    std::cout << (FixedPoint2{ -0.75 } + FixedPoint2{ 1.50 } == FixedPoint2{ 0.75 }) << '\n';
}

int main() {
    testAddition();

    FixedPoint2 a{-0.48};
    std::cout << a << '\n';

    std::cout << -a << '\n';

    std::cout << "Enter a number: \n";
    std::cin >> a;

    std::cout << "You entered " << a << '\n';
    return 0;
}
