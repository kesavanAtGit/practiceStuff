#include <iostream>
#include <cmath>

class Point2d
{
private:
    double m_x{};
    double m_y{};

public:
    Point2d() = default;
    Point2d(double x, double y): m_x{x}, m_y{y} {}

    void print() const{
        std::cout << "Point2d(" << m_x << ", " << m_y << ") \n";
    }

    //double distanceTo(const Point2d& point) const{
    //    return std::sqrt((m_x - point.m_x) * (m_x - point.m_x) + (m_y - point.m_y) * (m_y - point.m_y));
    //}
    friend double distanceFrom(const Point2d& first, const Point2d& second);
};

double distanceFrom(const Point2d& first, const Point2d& second) {
    return std::sqrt((first.m_x - second.m_x) * (first.m_x - second.m_x) + (first.m_y - second.m_y) * (first.m_y - second.m_y));
}

int main()
{
    Point2d first{};
    Point2d second{ 3.0, 4.0 };
    first.print();
    second.print();

    std::cout << distanceFrom(first, second);
    return 0;
}
