#include <iostream>
#include "Point2d.h"
#include "Creature.h"

int main() {

    std::string name{};
    std::cin >> name;
    Creature creature{name, {4, 10}};

    std::cout << creature << '\n';

    creature.moveTo(10, 20);
    std::cout << creature << '\n';

    return 0;
}
