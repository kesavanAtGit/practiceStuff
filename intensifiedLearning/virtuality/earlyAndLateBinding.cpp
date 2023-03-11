#include <iostream>

int add(int x, int y) {
    return x + y;
}

int sub(int x, int y) {
    return x - y;
}

int main() {

    int input{};

    int x{};
    std::cin >> x;

    int y{};
    std::cin >> y;

    do {
        std::cin >> input;
    }while(input < 0 || input > 1);

    // late bind me daddy
    int (*fPtr) (int, int) {nullptr};
    switch(input) {
        case 0: fPtr = add; break;
        case 1: fPtr = sub; break;
    }

    std::cout << "The result is " << fPtr(x, y);
    return 0;
}
