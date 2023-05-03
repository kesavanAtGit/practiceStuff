#include <iostream>
#include <limits>
#include <exception>
#include <cstdlib>
#include <stdexcept> // for std::runtime_error
#include <string>
#include <cstring>

// notes for this lesson
// when handling derived classes the handler for a derived class should be defined first
// then the base class handler

class Exception: public std::exception{
private:
    std::string m_error{};

public:
    Exception(std::string_view error): m_error{error} {}
    const char* what() const noexcept override {
        return m_error.c_str();
    }
};

class IntArray {
private:
    int m_array[5]{};

public:
    IntArray() {}

    int& operator[](int index) {
        if(index < 0 || index > 3) {
            throw Exception{"invalid index"};
        }
        return m_array[index];
    }
};

int main() {
    IntArray array{};
    try {
        //std::string strMeDaddy{};
        // throws a allocation exception or std::length_error
        //strMeDaddy.resize(std::numeric_limits<std::size_t>::max());
        int value{array[10]};
    }catch(const std::length_error& exception) {
        std::cerr << "string too long \n";
    }
    catch(const std::exception& exception) {
        std::cerr << exception.what();
    }
    return 0;
}
