#include<iostream>
#include<string>
#include<array>

class Bird {
protected:
    std::string m_name{};
    std::string m_speak{};

    Bird(std::string name, std::string speak): m_name{name}, m_speak{speak} {}
    Bird(const Bird&) = default;
    Bird& operator=(const Bird&) = default;

public:
    std::string getName() const{return m_name;}
    virtual std::string speak() const{return m_speak;}
};

class Sparrow: public Bird {
public:
    Sparrow(std::string name)
        :Bird{name, "chirp"} {}

    std::string speak() const{return m_speak;}
};

class Duck: public Bird {
public:
    Duck(std::string name)
        :Bird{name, "goooo"} {}

    virtual std::string speak() const{return m_speak;}
};

int main() {

    const Duck ducki{"ducki"};
    const Duck dokie{"dokie"};
    const Duck duckie{"duckie"};

    //const auto& ducks{std::to_array<const Duck>({ducki, dokie, duckie})};
    //for(const auto& duck: ducks) {
    //    std::cout << duck.getName() << " " << duck.speak() << '\n';
    //}

    // so this is what you use virtual functions for baby
    const auto birds{std::to_array<const Bird*>({&ducki, &dokie, &duckie})};
    for(const auto& bird: birds) {
        std::cout << bird -> getName() << " " << bird -> speak() << '\n';
    }

    return 0;
}
