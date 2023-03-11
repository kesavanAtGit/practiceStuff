#ifndef CREATURE_H
#define CREATURE_H

#include <iostream>
#include <string>
#include "Point2d.h"

class Creature
{
private:
    std::string m_name{};
    Point2d m_location{};

public:
    Creature(std::string name, const Point2d location): m_name{name}, m_location{location} {}

    friend std::ostream& operator<< (std::ostream& out, const Creature& creature) {
        out << creature.m_name  << " " << creature.m_location;
        return out;
    }

    void moveTo(int x, int y) {
        m_location.setLocation(x, y);
    }
};

#endif
