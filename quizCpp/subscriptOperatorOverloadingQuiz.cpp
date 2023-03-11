#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
// this quiz really got me into thinking that I'm nowhere near there

struct StudentGrade
{
    std::string name{};
    char grade{};
};

class GradeMap
{
private:
    std::vector<StudentGrade> m_map{
        {"kesavan", 'A'},
        {"dhanush", 'B'},
    };

public:
    GradeMap() = default;
    //GradeMap(std::vector<StudentGrade>& map): m_map(map) {}
    void operator[] (int value);
    char& operator[] (std::string name);
};

char& GradeMap::operator[] (std::string name) {
    auto found{std::find_if(m_map.begin(), m_map.end(), [&](const auto& studentGrade) {
                return (studentGrade.name == name);
            })};
    if(found != m_map.end())
        return found -> grade;

    m_map.push_back({std::string{name}});
    return m_map.back().grade;
}

void GradeMap::operator[] (int value) {
    std::cout << m_map[value].name << " " << m_map[value].grade;
}

int main()
{
    GradeMap gradeMap{};
    char& myGrade{gradeMap["kesavan"]};

    std::cout << myGrade;

    return 0;
}
