#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class	Point {
public:
	Point();
	Point(const float, const float);
	Point(const Point&);
	Point& operator =(const Point&) = delete;
	~Point();

	Fixed	getX() const;
	Fixed	getY() const;
private:
	const Fixed x;
	const Fixed y;
protected:
};

std::ostream& operator <<(std::ostream& out, const Point& point);

#endif // POINT_HPP
