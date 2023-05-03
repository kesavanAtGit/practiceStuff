#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class String
{
private:
    std::string m_name{};
    std::string m_herName{};

public:
    String(std::string name, std::string herName): m_name{name}, m_herName{herName} {}
    friend std::ostream& operator<< (std::ostream& out, const String& s);
    friend bool operator< (const String& s1, const String& s2);
};

bool operator< (const String& s1, const String& s2) {
    if(s1.m_name == s2.m_name)
        return (s1.m_herName < s2.m_herName);
    else
        return (s1.m_name < s2.m_name);
}

std::ostream& operator<< (std::ostream& out, const String& s) {
    out << s.m_name << " " << s.m_herName;
    return out;
}

void sort(std::vector<String>& randomArray) {
    for(int startIndex{0}; startIndex < (randomArray.size()) - 1; ++startIndex) {
        int smallestIndex{startIndex};
        for(int currentIndex{ startIndex + 1 }; currentIndex < randomArray.size(); ++currentIndex) {
            if(randomArray[currentIndex] < randomArray[smallestIndex]) {
                smallestIndex = currentIndex;
            }
        }
        std::swap(randomArray[startIndex], randomArray[smallestIndex]);
    }
}

int main()
{
    std::vector<String> stringsBaby{
            {"abc", "zxy"},
            {"aaa", "bbb"},
    };

    // sort(stringsBaby);
    std::sort(stringsBaby.begin(), stringsBaby.end());

    for(auto string: stringsBaby)
        std::cout << string << "\n";

    return 0;
}
