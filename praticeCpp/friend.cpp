#include <iostream>
#include <string>

// class prototype
class someClass;

class Hello
{
private:
        bool n_value{};
public:
        Hello(bool value): n_value{value} {}
        // forward declare disPlayValue();
        void disPlayValue(const someClass& someclass);
};

class someClass
{
private:
    int m_value{};

public:
    someClass(int value) : m_value{value} {}

    // now reset functon is a friend function of this class
    friend void reset(someClass& someclass);
    friend void print(const someClass& someclass, const Hello& hello);

    // class Hello now is a friend of class someClass
    friend class Hello;

    // member function friend
    // this needs to have seen the full definition of the class Hello
    friend void Hello::disPlayValue(const someClass &someclass);
};

void Hello::disPlayValue(const someClass& someclass) {
    if(n_value)
        std::cout << someclass.m_value << "\n";
    else
        std::cout << "false me daddy \n";
}

void reset(someClass& someclass) {
    someclass.m_value = 0;
}

int main() {

    someClass someclass{31};
    Hello hello{true};

    hello.disPlayValue(someclass);
    return 0;
}
