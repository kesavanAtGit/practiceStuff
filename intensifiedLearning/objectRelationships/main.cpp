#include <iostream>

int main() {
    int array[2]{ 1, 3};
    int* arr{new int[2] {4, 43}};

    for(auto var: array)
        std::cout << var << " ";
    std::cout << '\n';

    for(int i{0}; i < 2; ++i) {
        std::cout << arr[i] << " ";
    }

    return 0;
}
