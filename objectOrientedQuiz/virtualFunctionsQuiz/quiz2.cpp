#include <iostream>
#include <vector>
#include <algorithm>

class Shape {
public:
    friend std::ostream& operator<< (std::ostream& out, const Shape& shape) {
        return shape.print(out);
    }

    virtual std::ostream& print(std::ostream& out) const{
        std::cout << "In base \n";
        return out;
    }

    virtual ~Shape() = default;
};

struct Point {
    int point1{};
    int point2{};

    friend std::ostream& operator<< (std::ostream& out, const Point point) {
        out << "Point(" << point.point1 << ", " << point.point2 << ")";
        return out;
    }
};

class Triangle : public Shape{
private:
    Point m_point1{};
    Point m_point2{};
    Point m_point3{};

public:
    Triangle(Point point1, Point point2, Point point3)
        :m_point1{point1}, m_point2{point2}, m_point3{point3} {}

    std::ostream& print(std::ostream& out) const {
        std::cout << "Triangle(" << m_point1 << ", " << m_point2  << ", " << m_point3 << ")";
        return out;
    }
};

class Circle : public Shape{
private:
    Point m_centerPoint{};
    int m_radius{};

public:
    Circle(Point centerPoint, int radius)
        :m_centerPoint{centerPoint}, m_radius{radius} {}

    std::ostream& print(std::ostream& out) const {
        std::cout << "Circle(" << m_centerPoint << ", " << "radius " << m_radius << ")";
        return out;
    }

    int getRadius() const{
        return m_radius;
    }
};

int getLargestRadius(std::vector<Shape*>& shapes) {
    int largestRadius{};
    for(auto* shape: shapes) {
        // if doesn't return a null pointer
        if(auto* castedShape{dynamic_cast<Circle*>(shape)}) {
            largestRadius = std::max(largestRadius, castedShape->getRadius());
        }
    }
    return largestRadius;
}

int main() {
    std::vector<Shape*> v{
            new Circle{Point{ 1, 2 }, 7},
            new Triangle{Point{ 1, 2 }, Point{ 3, 4 }, Point{ 5, 6 }},
            new Circle{Point{ 7, 8 }, 3}
    };

    std::cout << "The largest radius is: " << getLargestRadius(v) << '\n';

    for(const auto* shape: v)
        std::cout << *shape << '\n';

    for(const auto* shape: v)
        delete shape;

    return 0;
}
