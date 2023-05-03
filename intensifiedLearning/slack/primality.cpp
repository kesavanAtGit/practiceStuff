#include <iostream>
#include <cassert>
#include <math.h>

// function to get the gcd of two numbers
int gcd(int a, int b) {
    return (b == 0)? std::abs(a): gcd(b, a%b);
}

// the naive way
bool primalityCheck(int num) {

    if(num == 0 || num == 1)
        return false;

    for(int i{2}; i < num; i++) {
        if(num % i == 0)
            return false;
    }
    return true;
}

// trial division
int isPrime(int num) {
    assert( num > 1 && "Prime me daddy");

    for(int i{2}; i <= std::sqrt(num); ++i) {
        if (num % i == 0) {
            std::cout << num << " is not a prime \n";
            return 0;
        }
    }
    std::cout << num << " is a prime \n";
    return num;
}

int main() {

    //int num{20};

    //for(int i{0}; i <= num; i++) {
    //    if(primalityCheck(i))
    //        std::cout << i << " ";
    //}
    std::cout << gcd(10, 20);

    return 0;
}
