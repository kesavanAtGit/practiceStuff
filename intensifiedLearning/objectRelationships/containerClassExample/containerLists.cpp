#include <iostream>
#include "containerLists.h"

int main() {
    IntArray array { 10, 20, 30, 40, 50 };

    for(int i{0}; i < array.getLength(); ++i) {
        std::cout << array[i] << " ";
    }
    std::cout << '\n';

    array = { 44, 55, 2, 21, 120 };

    for(int i{0}; i < array.getLength(); ++i) {
        std::cout << array[i] << " ";
    }
    std::cout << '\n';

    return 0;
}
