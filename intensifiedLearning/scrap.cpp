#include <iostream>

// it is close enough
bool isClose(double a, double b, int epsilon) {
    return (std::abs(a - b) <= epsilon);
}

int printMeDaddy(int num) {
    int value{10};
    for(int i{1}; i < 6; ++i) {
        if(num % i > 0)
            value += 1;
    }
    return value;
}

int main()
{
    int result{printMeDaddy(10)};
    std::cout << result;
    return 0;
}
