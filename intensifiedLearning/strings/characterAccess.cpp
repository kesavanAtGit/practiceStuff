#include <iostream>
#include <string>
#include <cstring>

int main() {
    std::string name{"ram is a god"};
    char something[20];

    std::cout << something;

    // char Buf, nLength, nIndex
    // returns a size_type (no of chars copied)
    int length{static_cast<int>(name.copy(something, 3, 0))};
    std::cout << length << '\n';

    // this is bad
    something[length] = '\0';
    std::cout << something;

    return 0;
}
