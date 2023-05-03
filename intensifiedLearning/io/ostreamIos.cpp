#include <iostream>
#include <ios>
#include <iomanip>

// ostream me daddy

int main() {
    //std::cout.setf(std::ios::showpos);
    //std::cout << 23 << '\n';

    //std::cout.unsetf(std::ios::showpos);
    //std::cout << 23 << '\n';

    //std::cout.setf(std::ios::showpos | std::ios::uppercase);
    //std::cout << 123444344.3f << '\n';

    std::cout.setf(std::ios::hex, std::ios::basefield);
    std::cout << 20 << '\n';

    std::cout << std::oct << 10 << '\n';
    std::cout << std::dec << 10 << '\n';
    std::cout << std::hex << 10 << '\n';
    return 0;
}
