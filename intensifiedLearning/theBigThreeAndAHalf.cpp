#include <iostream>
#include <string>
#include <cstring>
#include <cassert>
#include <cstddef>

class String
{
private:
    std::size_t m_length{};
    char* m_str{};

public:
    String(const char* str="") {
        assert(str && "don't be a nullstring daddy");

        m_length = std::strlen(str) + 1;
        m_str = new char[m_length];

        for(int i{0}; i < m_length; ++i) {
            m_str[i] = str[i];
        }
    }

    void deepCopy(const String& str) {
        delete[] m_str;
        m_length = str.m_length;
        m_str = (str.m_str? new char[m_length]: nullptr);

        for(int i{0}; i < m_length; ++i) {
            m_str[i] = str.m_str[i];
        }
    }

    String(const String& str) {
        deepCopy(str);
    }

    String& operator= (const String& str) {
        if(this != &str)
            deepCopy(str);
        return *this;
    }

    ~String() {
        delete[] m_str;
    }

    char* getStr() {return m_str;}
};

int main() {
    String str{"ay mi amor"};
    std::cout << str.getStr() << "\n";

    String anotherStr = str;
    std::cout << anotherStr.getStr();

    return 0;
}
