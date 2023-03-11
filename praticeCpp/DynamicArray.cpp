#include <iostream>
#include <utility>
#include <algorithm>
#include <string>

int getNames()
{
    std::cout << "How many names would you like to enter?";
    int names{};
    std::cin >> names;
    return names;
}

const std::string* readNames(std::string* names, int namesLength)
{
    for(int i{0}; i < namesLength; ++i)
    {
        std::cout << "Enter name " << i + 1 << ": ";
        std::getline(std::cin >> std::ws, names[i]);
    }
    return names;
}

const std::string* sortNames(std::string* names, int namesLength)
{
    int largestIndex{};
    for(int index{0}; index < namesLength - 1; ++index)
    {
        for(int currentIndex{index}; currentIndex < namesLength; ++currentIndex)
        {
            if(names[currentIndex] > names[currentIndex + 1])
                    largestIndex= currentIndex;
        }
        std::swap(names[index], names[largestIndex]);
    }
    return names;
}

void printNames(std::string* names, int namesLength)
{
    std::cout << "Here is your sorted list: \n";

    for(int i{0}; i < namesLength; ++i)
        std::cout << "Name " << i + 1 << ": " << names[i] << "\n";
}

int main()
{
    int namesLength{getNames()};
    auto* names{new std::string[namesLength]};

    readNames(names, namesLength);
    sortNames(names, namesLength);
    printNames(names, namesLength);

    // could do this
    // std:;sort(names, names + namesLength);

    return 0;
}
