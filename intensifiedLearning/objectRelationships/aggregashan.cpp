#include <iostream>
#include <string>
#include <vector>
#include <functional>

class Teacher
{
private:
    std::string m_name{};

public:
    Teacher(const std::string& name): m_name{name} {}

    const std::string& name() const {
        return m_name;
    }
};

class Department
{
private:
    std::vector<std::reference_wrapper<const Teacher>> m_stringRefs{};

public:
    void add(const Teacher& teacher) {
        m_stringRefs.push_back(teacher);
    }

    friend std::ostream& operator<< (std::ostream& out, const Department& department) {
        for(const auto& teacher: department.m_stringRefs)
            out << teacher.get().name() << " ";

        return out;
    }
};

int main() {
    Teacher t1{"gam"};
    Teacher t2{"bam"};
    Teacher t3{"wam"};

    {
        Department department{};
        department.add(t1);
        department.add(t2);
        department.add(t3);

        std::cout << department << '\n';
    }

    std::cout << t1.name() << " still exists" << '\n';
    std::cout << t2.name() << " still exists" << '\n';
    std::cout << t3.name() << " still exists" << '\n';

    return 0;
}
