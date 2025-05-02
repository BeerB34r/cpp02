#include <iostream>

#include "Point.hpp"

bool	bsp(const Point a, const Point b, const Point c, const Point p);

int	main() {
	Point	a(1,1);
	Point	b(3,1);
	Point	c(1,3);
	Point	outside(4,4);
	Point	inside(1.5,1.5);
	Point	border(1,2);

	std::cout << "A = " << a << std::endl;
	std::cout << "B = " << b << std::endl;
	std::cout << "C = " << c << std::endl;
	std::cout << "outside == " << outside << std::endl;
	std::cout << "inside == " << inside << std::endl;
	std::cout << "border == " << border << std::endl;
	std::cout << "(outside ∈ △ABC) == " << (bsp(a,b,c,outside) ? "true" : "false") << std::endl;
	std::cout << "(inside ∈ △ABC) == " << (bsp(a,b,c,inside) ? "true" : "false") << std::endl;
	std::cout << "(border ∈ △ABC) == " << (bsp(a,b,c,border) ? "true" : "false") << std::endl;
}
