#include <iostream>
#include <new>
#include <ostream>
#include <iomanip>

int main() {
    //std::cout.setf(std::ios::fixed, std::ios::floatfield);
    //std::cout << 1234435353.3f;

    std::cout << std::fixed;
    std::cout << std::showpoint;
    std::cout << std::setprecision(6) << 150.2f;
    return 0;
}
