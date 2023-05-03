#include <iostream>
#include <new>
#include <sstream>
#include <string>

int main () {
    std::stringstream str{"10"};
    std::stringstream anotherStr{"3.2"};

    int value{};
    double something{};
    str >> value;
    anotherStr >> something;

    //call the clear() on a stringstream when clearing it for reuse
    std::cout << value << " " << something;
    return 0;
}

