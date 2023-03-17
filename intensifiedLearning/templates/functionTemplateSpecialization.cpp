#include <iostream>
#include <string>

// let's specialize the function templates
template <typename T>
class Score {
private:
    T m_value{};

public:
    Score(T value)
        :m_value{value} {}

    // will look like this for the data type char*
    // Score<char*>::Score(char* score)
    //      :m_value{score} {}

    ~Score() {}; // an explicit destructor to specialize it

    void print() {
        std::cout << m_value << '\n';
    }
};

template<>
Score<char*>::Score(char* value) {
    if(!value)
        return;

    int length{};
    while(value[length] != '\0')
        ++length;
    ++length; // for the null terminator

    m_value = new char[length];
    for(int i{0}; i < length; ++i) {
        m_value[i] = value[i];
    }
}

template<>
Score<char*>::~Score() {
    delete[] m_value;
}

template<>
void Score<double>::print() {
    std::cout << std::scientific << m_value << '\n';
}

int main() {

    std::string score{};
    std::cout << "Enter your score in words: ";
    std::cin >> score;

    Score<char*> ptr{score.data()};
    ptr.print();

    score.clear();
    ptr.print();

    return 0;
}
