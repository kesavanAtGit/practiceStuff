#ifndef POINT2D_H
#define POINT2D_H

#include <iostream>

class Point2d
{
private:
    int m_x{};
    int m_y{};

public:
    Point2d(int x=0, int y=0): m_x{x}, m_y{y} {}

    friend std::ostream& operator<< (std::ostream& out, const Point2d point) {
        out << point.m_x << " " << point.m_y;
        return out;
    }

    void setLocation(int x, int y ) {
        m_x = x;
        m_y = y;
    }
};

#endif
