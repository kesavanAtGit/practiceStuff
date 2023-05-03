#include <iostream>
#include <ostream>
#include <iomanip>

int main() {
    std::cout.setf(std::ios::left, std::ios::adjustfield);
    std::cout.width(10);
    std::cout.fill('*');
    std::cout << -1234 << '\n';
    std::cout << std::setw(10) << std::right << -12455 << '\n';
    //std::cout << std::setw(10) << std::left << -12455 << '\n';
    //std::cout << std::setw(10) << std::internal << -12455 << '\n';
    return 0;
}
