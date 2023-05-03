#include <iostream>
#include <cmath>

int main() {

    int input{};
    std::cout << "Enter the integer: \n";
    std::cin >> input;

    try {
        if(input <= 0.0) {
            std::cout << "can't take sqrt() for " << input << '\n';
            throw -1;
        }
        else {
            std::cout << std::sqrt(input) << '\n';
        }
    }
    catch(int something) {
        std::cerr << "catch this bad boy " << something << '\n';
        try {
            throw 1.2;
        }
        catch(double) {
            std::cerr << "throwing a doubley double right at ya face \n";
        }
    }
    catch(const char*) {
        std::cerr << "I dunno what to do here \n";
    }
    return 0;
}
