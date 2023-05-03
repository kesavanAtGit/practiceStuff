#include <iostream>
#include <iterator>
#include <memory>
#include <string>

class Person {
private:
    std::string m_name{};
    std::weak_ptr<Person> m_partner{};

public:
    Person(const std::string& name)
        :m_name{name} {
            std::cout << m_name << " created successfully \n";
        }

    ~Person() {
        std::cout << m_name << " destroyed successfully \n";
    }

    friend bool partnerUp(std::shared_ptr<Person>& personOne, std::shared_ptr<Person>& personTwo) {
        if(!personOne || !personTwo)
            return false;

        personOne->m_partner = personTwo;
        personTwo->m_partner = personOne;

        std::cout << personOne->m_name << " is now partnered with " << personTwo->m_name << '\n';
        return true;
    }

    const std::shared_ptr<Person> getPartner() {
        return m_partner.lock();
    }
    const std::string& getName() {return m_name;}
};

std::weak_ptr<Person> weakPtr() {
    auto ptr{std::make_shared<Person>("ram")};
    std::cout << ptr->getName() << '\n';
    return std::weak_ptr<Person>{ptr};
}

Person* dumbPtr() {
    auto ptr{std::make_unique<Person>("kesavan")};
    return ptr.get();
}

int main() {
    auto dumbptr{dumbPtr()};
    std::cout << "dumb ptr is " << (dumbptr == nullptr? "null \n": "non-null \n");
    return 0;
}
