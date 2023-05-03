#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

class Car
{
    private:
        std::string m_make{};
        std::string m_model{};

    public:
        Car(std::string car, std::string anotherCar): m_make{car}, m_model{anotherCar} {}
        friend bool operator==(const Car& car, const Car& anotherCar);
        friend bool operator<(const Car& car, const Car& anotherCar);
        friend std::ostream& operator<< (std::ostream& out, const Car& car);
};

bool operator< (const Car& s1, const Car& s2) {
    if(s1.m_make == s2.m_make)
        return (s1.m_model < s2.m_model);
    else
        return (s1.m_make < s2.m_make);
}

std::ostream& operator<< (std::ostream& out, const Car& car) {
    out << car.m_make << " " << car.m_model;
    return out;
}

void sort(std::vector<Car>& randomArray) {
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
    std::vector<Car> cars{
            { "Toyota", "Corolla" },
            { "Honda", "Accord" },
            { "Toyota", "Camry" },
            { "Honda", "Civic" }
    };

    // sort(cars);
    std::sort(cars.begin(), cars.end());
    for (const auto& car : cars)
        std::cout << car << '\n'; // requires an overloaded operator<<

    return 0;
}
