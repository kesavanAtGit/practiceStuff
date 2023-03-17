#include <iostream>

class Base {
public:
    friend std::ostream& operator<< (std::ostream& out, Base& base) {
        return base.print(out);
    }

    virtual std::ostream& print(std::ostream& out) {
        out << "Base \n";
        return out;
    }

    virtual ~Base() = default;
};

struct Employee {
    std::string m_name{};
    int m_id{};

    friend std::ostream& operator<< (std::ostream& out, Employee& e) {
        out << "Employee (" << e.m_name << ", " << e.m_id << ") \n";
        return out;
    }
};

// i don't fucking know how to use enums and structs to their full ability
// i don't
// i just don't

class Derived: public Base {
private:
    Employee m_employee{};

public:
    Derived(Employee employee)
        :m_employee(employee) {}

    std::ostream& print(std::ostream& out) {
        out << m_employee;
        return out;
    }
};

int main() {
    Base base{};
    Employee employee{"kesavan", 10};
    Derived derived{employee};

    std::cout << base;
    std::cout << derived;
    return 0;
}
