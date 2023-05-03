#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

int main () {
    std::srand(std::time(nullptr));

    std::string str{};
    str.reserve(32);

    for(int i{0}; i < 32; ++i) {
        str += 'x' + std::rand() % 10;
    }

    std::cout << str;

    return 0;
}
