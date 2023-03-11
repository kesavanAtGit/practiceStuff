#include <iostream>
#include <string>

class Animal {

private:
    int m_legs{};
    std::string m_name{};

public:
    Animal(int legs, std::string name)
        : m_legs{legs}, m_name{name} {}

    int getLegs() {return m_legs;}
    const std::string& getName() const{return m_name;}
};

class Babies {

private:
    int m_babies{};

public:
    Babies(int babies): m_babies{babies} {}
    int getBabies() {return m_babies;}
};

class Dog : public Animal, Babies {

public:
    Dog(int legs, std::string name): Animal{legs, name}, Babies{210} {}

    void printLegs() {
        std::cout << getName() << " has " << getLegs()  << '\n';
        std::cout << "Really " << getBabies();
    }
};

int main() {
    Dog dog{10, "Alice"};
    dog.printLegs();
    return 0;
}
