#include <iostream>
#include <limits>
#include <string>
#include <vector>
#include <cstddef>
#include <iterator>
#include <algorithm>
#include <functional>
#include <limits>

struct StudentInfo
{
    std::string name{};
    int grade{};
};

int getNumberOfStudents()
{
    int noOfStudents{};
    do
    {
        std::cout << "How many students would you like to enter? ";
        std::cin >> noOfStudents;

        if(!std::cin)
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    } while(noOfStudents <= 0);
    return noOfStudents;
}

// prompt the user for the names and grades
auto getNamesAndGrades()
{
    using Students = std::vector<StudentInfo>;

    int totalStudents{getNumberOfStudents()};
    Students student(static_cast<Students::size_type>(totalStudents));

    for(auto& students: student)
        std::cin >> students.name >> students.grade;

    return student;
}

bool greater(StudentInfo& info1, StudentInfo& info2)
{
    return ( info1.grade > info2.grade );
}

int main()
{

    std::vector<StudentInfo> student{getNamesAndGrades()};

    // sort the list by the highest grade
    std::sort(student.begin(), student.end(), greater);

    for(auto var: student)
        std::cout << var.name << " got a grade of " << var.grade << "\n";

    return 0;
}
