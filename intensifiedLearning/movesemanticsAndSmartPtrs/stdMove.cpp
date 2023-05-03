#include <iostream>
#include <string>
#include <utility>
#include <vector>

// move me daddy using std::move()
template <class T>
void move(T& one, T& two) {
    T tmp{std::move(one)};
    one = std::move(two);
    two = std::move(tmp);
}

int main() {
    // can also use std::move() with container classes like vector
    // moved from object can be assigned using the = operator
    std::vector<std::string> strArray{};
    std::string x{"piya"};

    std::cout << "copying string \n";
    strArray.push_back(x);
    std::cout << x << '\n';
    std::cout << strArray[0] << '\n';

    std::cout << '\n';

    std::cout << "moving string \n";
    strArray.push_back(std::move(x));
    std::cout << x << '\n';
    std::cout << strArray[0] << strArray[1] << '\n';

    //std::string y{"kesavan"};
    //std::cout << "before move \n";
    //std::cout << x << " " << y << '\n';

    //move(x, y);
    //std::cout << "after move \n";
    //std::cout << x << " " << y << '\n';
    return 0;
}
