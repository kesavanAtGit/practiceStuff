#include <iostream>
#include <string>

class Car
{
private:
    std::string m_name{};
    int m_id{};

public:
    Car(std::string name, int id): m_name{name}, m_id{id} {}

    const std::string& getCar() const{return m_name;}
    int getId() const{return m_id;}
};

class CarLot
{
private:
    static Car s_carLot[4];

public:
    // restriction from creating this object
    CarLot() = delete;
    static Car* getCar(int id) {
        for(int i{0}; i < 4; ++i) {
            if(s_carLot[i].getId() == id)
                return &(s_carLot[i]);
        }
        return nullptr;
    }
};
Car CarLot::s_carLot[4]{{"ford", 12}, {"bmw", 10}, {"corolla", 23}, {"lambhorghini", 2}};

class Driver
{
private:
    std::string m_name{};
    int m_Cardid{};

public:
    Driver(std::string name, int cardId): m_name{name}, m_Cardid{cardId} {}

    const std::string& getDriver() const{return m_name;}
    int getCardId() {return m_Cardid;}
};

int main() {
    Driver driver{"Julian", 34};

    // returns the address if the car found
    Car* car{CarLot::getCar(driver.getCardId())};

    if(car)
        std::cout << driver.getDriver() << " is driving " <<  car->getCar() << '\n';
    else
        std::cout << "No cars found\n";

    return 0;
}
