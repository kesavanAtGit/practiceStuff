#include <ios>
#include <iostream>
#include <iterator>
#include <cassert>
#include <limits>
#include <functional>

void ignoreExtraCharacters()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int getUserInput()
{
    std::cout << "Enter an integer: ";
    int num{};
    std::cin >> num;
    return num;
}

char getUserOperation()
{
    while (true)
    {
        std::cout << "Enter a mathematical operation : '+', '-', '*', '/' ";
        char ch{};
        std::cin >> ch;

        // clear and ignore if eztraction failed
        if(!std::cin)
        {
            std::cin.clear();
            ignoreExtraCharacters();
        }
        switch(ch)
        {
            case '+':
            case '-':
            case '*':
            case '/':
                return ch;
            default:
                assert("should be a valid character");
        }
    }
}

// functions for the operations
int add(int x, int y) { return x + y; }
int sub(int x, int y) { return x - y; }
int mul(int x, int y) { return x * y; }
int divide(int x, int y) { return x / y; }

// create a type alias for the arithmetic operation
using ArithmeticFunction = std::function<int(int, int)>;

ArithmeticFunction fcnPtr(char op)
{
    switch(op)
    {
        case '+': return &add;
        case '-': return &sub;
        case '*': return &mul;
        case '/': return &divide;
    }
    return nullptr;
}

int main()
{
    // stores a pointer to a function
    int a{getUserInput()};
    int b{getUserInput()};
    auto asdf{fcnPtr(getUserOperation())};
    std::cout << asdf(a,b);
    return 0;
}
