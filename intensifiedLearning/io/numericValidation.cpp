#include <iostream>
#include <algorithm> // for std::equal
#include <map>
#include <string>
#include <string_view>
#include <ranges>
#include <cctype>

bool inputMatches(std::string_view input, std::string_view pattern) {
    if(input.length() != pattern.length()) {
        return false;
    }

    static std::map<char, int(*)(int)> validators {
        {'#', &std::isdigit},
        {'_', &std::isspace},
        {'@', &std::isalpha},
        {'?', [](int) {return 1;}}
    };

    return std::ranges::equal(input, pattern, [](char ch, char mask) -> bool {
                if(auto found{validators.find(mask)}; found != validators.end()) {
                    return (*found->second)(ch);
                }

                else {
                    return (ch == mask);
                }
            });
}

int main() {
    std::string phoneNumber{};

    do {
        std::cout << "Enter your phone number (###) ###-####: ";
        std::getline(std::cin, phoneNumber);
    }while(!inputMatches(phoneNumber, "(###) ###-####"));

    std::cout << "Your phoneNumber is  " << phoneNumber;
    return 0;
}
