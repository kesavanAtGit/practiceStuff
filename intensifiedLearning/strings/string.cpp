#include <iostream>
#include <string>
#include <vector>

// std::string and std::wstring

int main () {

    std::string name{"priyaa"};
    std::string anotherName{"kesav"};

    std::string nameSliced{name, 3};
    std::cout << nameSliced;

    //std::cout << name.find_last_not_of('p');
    return 0;
}
