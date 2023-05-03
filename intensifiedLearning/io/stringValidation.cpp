#include <iostream>
#include <algorithm> // for std::all_of
#include <cctype>
#include <ranges>
#include <string>
#include <string_view>

// input me daddy
bool isValidName(std::string_view name) {
    return std::ranges::all_of(name, [](char ch) {
                return (std::isalpha(ch) || std::isspace(ch));
            });
}

int main() {
    std::string name{};

    do {
        std::cout << "Enter your name: ";
        std::getline(std::cin, name);
    }while(!isValidName(name));

    std::cout << "Hello " << name;
    return 0;
}
