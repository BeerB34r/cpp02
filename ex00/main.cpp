#include <iostream>

#include "Fixed.hpp"

void	exampleFunc() {
	Fixed a;
	Fixed b(a);
	Fixed c;

	c = b;

	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
}

int	main() {
	exampleFunc();

	Fixed a;
	Fixed b(a);
	Fixed c;

	a.setRawBits(1);
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	
	c = a;
	a.setRawBits(c.getRawBits() + 1);

	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
}
