#include <iostream>
#include <string>
#include <string_view>
#include <optional>
#include <charconv>

//std::optional<int> quotient(int numerator, int denominator) {
//    if(denominator == 0) {
//        return std::nullopt;
//    }
//    return numerator / denominator;
//}

std::optional<int> intAge(std::string_view age) {
    int result{};
    auto end{age.data() + age.size()};
    if(std::from_chars(age.data(), end, result).ptr != end) {
        return {};
    }
    if(result <= 0) {
        return {};
    }
    return result;
}

int main() {

    int age{};

    while(true) {
        std::cout << "Enter your age: ";
        std::string strAge{};
        std::getline(std::cin >> std::ws, strAge);

        if(auto extractedAge{intAge(strAge)}) {
            age = *extractedAge;
            break;
        }
    }

    std::cout << age;

    //std::string age{"10"};
    //int numAge{};

    //auto [ptr, ec] = std::from_chars(age.data(), age.data() + age.size(), numAge);
    //if(ec == std::errc{}) {
    //    std::cout << "oh yeah \n";
    //}
    //else {
    //    std::cout << "oh no \n";
    //}

    //auto value{quotient(20, 10)};

    //if(value.has_value()) {
    //    std::cout << value.value();
    //}
    //else {
    //    std::cout << "there's no value \n";
    //}
    return 0;
}
