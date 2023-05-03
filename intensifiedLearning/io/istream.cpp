#include <iostream>
#include <istream>
#include <cstring>
#include <string>

int main() {
    char ch[100] {};

    // can read upto 99 characters
    //std::cin.getline(ch, 100);
    //std::cout << ch << '\n';
    //std::cout << std::cin.gcount() << '\n';

    std::string str{};
    std::cin.ignore();
    std::cin.putback('s');
    std::cout << static_cast<char>(std::cin.peek()) << '\n';
    std::getline(std::cin, str);
    std::cout << str;


    //still no so sure what this does let's dig into this later
    //std::cin.unget();
    return 0;
}
