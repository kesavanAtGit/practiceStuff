#include <iostream>
#include <limits>
#include <system_error>

int main() {
    int age{};

    while(true) {
        std::cout << "Enter your age: ";
        std::cin >> age;

        if(std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if(std::cin.gcount() > 1)
            continue;

        if(age <= 0)
            continue;

        break;
    }
    std::cout << "The age user entered is: " << age << '\n';
    return 0;
}
