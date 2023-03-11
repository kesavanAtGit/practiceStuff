#include <cstdlib>
#include <iostream>
#include <random>
#include <ctime>

// inclusively
// 1 3
int getRandomNumber(int min, int max) {
    static constexpr double fraction{ 1.0 / (RAND_MAX + 1.0) };
    return min + static_cast<int>((max - min + 1) * (std::rand() * fraction));
}

int main() {

    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    std::rand();

    std::cout << getRandomNumber(1, 3);

    return 0;
}
