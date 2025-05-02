

#include "Point.hpp"

Point::Point() {
}

Point::Point(const float x, const float y) : x(x), y(y) {
}

Point::Point(const Point& other) : x(other.x), y(other.y) {
}

Point::~Point() {
}

Fixed	Point::getX() const { return this->x; }

Fixed	Point::getY() const { return this->y; }

std::ostream& operator <<(std::ostream& out, const Point& point) {
	out << point.getX() << "," << point.getY();
	return out;
}
