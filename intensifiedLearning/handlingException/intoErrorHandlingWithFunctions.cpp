#include <iostream>

void B() {
    std::cout << "start b \n";
    throw -1;
}

void A() {
    try {
        std::cout << "start a \n";
        B();
    }catch (int) {
        std::cout << "int exception handled in a \n";
    }
}

// this function delegates the authority to handle the exception to the caller function
// which here is the try block
int returnZero(bool& success) {
    if(success)
        return 0;

    throw -1;
    std::cout << "this never prints \n";
}

int main() {
    bool success{};
    try {
        returnZero(success);
    }catch (double) {
        std::cout << "catch me daddy \n";
        // catch-all handler using a ellipsis
    }catch(...) {
        std::cout << "catch all daddy \n";
    }
    return 0;
}
