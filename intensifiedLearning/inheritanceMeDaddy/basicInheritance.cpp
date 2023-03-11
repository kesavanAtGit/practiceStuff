#include <iostream>
#include <string>

// inherit me daddy
class Person {
public:
    std::string m_name{};
    int m_age{};

    Person(std::string name="", int age=0): m_name{name}, m_age{age} {}

    const std::string& getName() const{return m_name;}
    int getAge() const{return m_age;}
};

class BaseBallPlayer : public Person {
public:
    double m_averageScore{};
    int m_homeRuns{};

    BaseBallPlayer(const std::string name, int age, double averageScore, int homeRuns)
        : Person{name, age}, m_averageScore{averageScore}, m_homeRuns{homeRuns} {}

    double getAvgScore() {return m_averageScore;}
    int getHomeRuns() {return m_homeRuns;}
};

class Employee : public Person {
public:
    double m_hourlySalary{};
    int m_employeeID{};

    Employee(double hourlySalary, int employeeID)
        : m_hourlySalary{hourlySalary}, m_employeeID{employeeID} {}
};

int main() {
    BaseBallPlayer mamba{"Kobe", 34, 23.32, 10};
    std::cout << mamba.getName() << '\n';
    std::cout << mamba.getAge() << '\n';
    std::cout << mamba.getAvgScore() << '\n';
    std::cout << mamba.getHomeRuns() << '\n';
    return 0;
}
