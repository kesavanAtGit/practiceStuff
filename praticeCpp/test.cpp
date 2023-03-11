#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::vector<int> arr{12,23,4};
    int guess{};
    std::cin >> guess;

    // finds me the closest number to the guess
    auto found{std::min_element(arr.begin(), arr.end(), [=](int a, int b) {
                return (std::abs(a - guess) < std::abs(b - guess));
            })};

    if(std::abs(*found - guess) <= 4)
        std::cout << "Try " << *found << " next time.\n";

    return 0;
}
