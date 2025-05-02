#include "Point.hpp"

// i didnt implement the binary space partition algorithm, mostly cuz it didnt
// feel like a good answer to a relatively simple geometry question lmao

// my solution instead uses a barycentric coordinate system to determine wether
// or not it is within the confines of the given triangle

Fixed	area(const Point a, const Point b, const Point c) {
	Fixed	out;

	out = Fixed(0.5f) * ( ((b.getY() * Fixed(-1)) * c.getX())
			+ (a.getY() * ((b.getX() * Fixed(-1)) + c.getX()))
			+ (a.getX() * (b.getY() - c.getY()))
			+ (b.getX() * c.getY()));
	return out;
}

bool	bsp(const Point a, const Point b, const Point c, const Point p) {
	Fixed	A = area(a,b,c);
	Fixed	S((Fixed(1)/(Fixed(2)*A)) * (
				a.getY() * c.getX() - a.getX() * c.getY()
				+ (c.getY() - a.getY()) * p.getX()
				+ (a.getX() - c.getX()) * p.getY())
			);
	Fixed	T((Fixed(1)/(Fixed(2)*A)) * (
				a.getX() * b.getY() - a.getY() * b.getX()
				+ (a.getY() - b.getY()) * p.getX()
				+ (b.getX() - a.getX()) * p.getY()
				)
			);

	if (S.toFloat() <= 0) return false;
	if (T.toFloat() <= 0) return false;
	if (Fixed(1) - S - T <= 0) return false;
	return true;
}
