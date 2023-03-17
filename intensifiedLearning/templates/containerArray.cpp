#include <iostream>
#include "array.h"
#include "array.cpp"

// let's learn the heck out of templates

int main() {
    Array<int> array{10};
    Array<double> anotherArray{10};

    for(int i{0}; i < array.getLength(); ++i) {
        array[i] = i;
        anotherArray[i] = i + 0.5;
    }

    for(int i{(array.getLength()) - 1}; i >= 0; --i) {
        std::cout << array[i] << '\t' << anotherArray[i] << '\n';
    }

    return 0;
}
