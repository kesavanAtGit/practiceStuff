#include <iostream>
#include <cstring>

// assign and swap me daddy

int main() {
    std::string name{"kesavan"};
    const char* someName{"kaveen"};

    std::string anotherName{};
    // string, index, unLength
    anotherName.assign(someName, 1, 3);

    std::string swapString{};
    swapString.swap(name);

    std::cout << swapString;
    return 0;
}
