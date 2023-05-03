#include <iostream>
#include <string>
#include <sstream>

// inserting a type into a stream and returning it as a string
template <typename T>
inline std::string toString(T someType) {
    std::ostringstream strMeDaddy{};
    strMeDaddy << someType;
    return strMeDaddy.str();
}

// extrating string into compatible type from a stream
template <typename T>
inline bool FromString(const std::string& someString, T& someType) {
    std::istringstream strMeAgain{someString};
    return !(strMeAgain >> someType).fail();
}

int main() {

    //double x{};
    //std::string one{"xyz"};
    //if(FromString(one, x)) {
    //    std::cout << x;
    //}else {
    //    std::cout << "can't do the extraction daddy \n";
    //}

    std::string stringuh{std::to_string(10)};
    std::cout << stringuh << " " << typeid(stringuh).name();
    return 0;
}
