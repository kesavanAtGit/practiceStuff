#include <iostream>
#include <fstream>

int main() {

    // text me daddy

    std::fstream anotherFile{"test.txt", std::ios::in};
    std::string str{};

    anotherFile.seekg(5, std::ios::beg);
    std::getline(anotherFile, str);
    std::cout << str << '\n';
    std::cout << anotherFile.tellg();

    anotherFile.close();
    return 0;
}
