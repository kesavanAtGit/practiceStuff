#include <iostream>
#include <numeric>
#include "score.h"

int main()
{
    Score s1{10};
    Score s2{20};

    std::cout << s1 + 10;
    return 0;
}

