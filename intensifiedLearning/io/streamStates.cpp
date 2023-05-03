#include <iostream>
#include <ios>

int main () {
    std::cout << "Enter your name: ";
    std::string name{};
    std::getline(std::cin, name);

    if(std::ios::failbit) {
        std::cout << "bad extraction \n";
        std::cin.clear();
    }
    return 0;
}
