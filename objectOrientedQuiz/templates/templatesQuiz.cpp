#include <iostream>
#include <string>

template <typename T, typename S>
class Pair {
protected:
   T m_first{};
   S m_second{};

public:
   Pair(T first, S second)
       :m_first{first}, m_second{second} {}

   T first() const {
       return m_first;
   }

   S second() const {
       return m_second;
   }
};

template <typename S>
class StringValuePair: public Pair<std::string, S> {
public:
    StringValuePair(std::string value, S type)
        :Pair<std::string, S>{value, type} {}

    std::string first() {
        return this -> m_first;
    }

    S& second() {
        return this -> m_second;
    }
};


int main() {
    StringValuePair<int> svp{"hello", 5};
    std::cout << "Pair: " << svp.first() << ' ' << svp.second() << '\n';
    return 0;
}
