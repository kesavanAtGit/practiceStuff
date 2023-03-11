#include <iostream>
#include <string>

class Animal {
private:
    std::string m_name{};

public:
    Animal(std::string name)
        :m_name{name} {}

    virtual std::string speak() const = 0;

    virtual ~Animal() = default;
};

std::string Animal::speak() const {
    return "Sound daddy \n";
}

class Dog : public Animal {
public:
    Dog(std::string name)
        :Animal{name} {}

    std::string speak() const override{
        return "wow wow \n";
    }
};

class Cow: public Animal {
public:
    Cow(std::string name)
        :Animal{name} {}

    std::string speak() const override{
        return Animal::speak();
    }
};
int main() {
    Cow cow{"lakshmi"};
    std::cout << cow.speak();

    Animal& c{cow};
    std::cout << c.speak();
    return 0;
}
