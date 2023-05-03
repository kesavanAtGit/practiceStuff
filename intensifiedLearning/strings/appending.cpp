#include <iostream>
#include <iterator>
#include <string>

int main() {
    std::string confession{"I"};
    confession.append(" love you Priya");

    //std::cout << confession << '\n';

    std::string subString{};
    //subString.append(confession, 0, 10);

    //subString.append(5, 'u');

    subString.append(confession.begin(), confession.end());
    std::cout << subString;
    return 0;
}
