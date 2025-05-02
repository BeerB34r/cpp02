#include <iostream>

#include "Fixed.hpp"

void	exampleFunc() {
	Fixed			a;
	Fixed	const	b(Fixed(5.05f) * Fixed(2));

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << Fixed::max(a, b) << std::endl;
}

void	testIncrementation() {
	Fixed a;

	std::cout << "initial value of a == " <<  a << std::endl;
	std::cout << "postfix incrementation; a++ == " << a++ << std::endl;
	std::cout << "a == " << a << std::endl;
	std::cout << "prefix incrementation; ++a == " << ++a << std::endl;
	std::cout << "a == " << a << std::endl;
}

void	testDecrementation() {
	Fixed a(1);

	std::cout << "initial value of a == " <<  a << std::endl;
	std::cout << "postfix decrementation; a-- == " << a-- << std::endl;
	std::cout << "a == " << a << std::endl;
	std::cout << "prefix decrementation; --a == " << --a << std::endl;
	std::cout << "a == " << a << std::endl;
}

void	testAddition() {
	std::cout << "2 + 1 == " << Fixed(Fixed(2) + Fixed(1)) << std::endl;
	std::cout << "0.2 + 0.1 == " << Fixed(Fixed(0.2f) + Fixed(0.1f)) << std::endl;
	std::cout << "1 + 0.1 == " << Fixed(Fixed(1) + Fixed(0.1f)) << std::endl;
	std::cout << "1 + 0 == " << Fixed(Fixed(1) + Fixed(0)) << std::endl;
}

void	testSubtraction() {
	std::cout << "2 - 1 == " << Fixed(Fixed(2) - Fixed(1)) << std::endl;
	std::cout << "0.2 - 0.1 == " << Fixed(Fixed(0.2f) - Fixed(0.1f)) << std::endl;
	std::cout << "1 - 0.1 == " << Fixed(Fixed(1) - Fixed(0.1f)) << std::endl;
	std::cout << "1 - 0 == " << Fixed(Fixed(1) - Fixed(0)) << std::endl;
}

void	testMultiplication() {
	std::cout << "2 * 1 == " << Fixed(Fixed(2) * Fixed(1)) << std::endl;
	std::cout << "0.2 * 0.1 == " << Fixed(Fixed(0.2f) * Fixed(0.1f)) << std::endl;
	std::cout << "1 * 0.1 == " << Fixed(Fixed(1) * Fixed(0.1f)) << std::endl;
	std::cout << "1 * 0 == " << Fixed(Fixed(1) * Fixed(0)) << std::endl;
}

void	testDivision() {
	std::cout << "2 / 1 == " << Fixed(Fixed(2) / Fixed(1)) << std::endl;
	std::cout << "0.2 / 0.1 == " << Fixed(Fixed(0.2f) / Fixed(0.1f)) << std::endl;
	std::cout << "1 / 0.1 == " << Fixed(Fixed(1) / Fixed(0.1f)) << std::endl;
	std::cout << "0 / 1 == " << Fixed(Fixed(0) / Fixed(1)) << std::endl;
	try {
		std::cout << "1 / 0 == " << Fixed(Fixed(1) / Fixed(0)) << std::endl;
	} catch (std::exception& err) {
		std::cout << err.what() << std::endl;
	}
}

void	testComparison() {
	std::cout << "1 < 2 == " << (Fixed(1) < Fixed(2)) << std::endl;
	std::cout << "2 < 1 == " << (Fixed(2) < Fixed(1)) << std::endl;
	std::cout << "2 > 1 == " << (Fixed(2) > Fixed(1)) << std::endl;
	std::cout << "1 > 2 == " << (Fixed(1) > Fixed(2)) << std::endl;
	std::cout << "1 > 1 == " << (Fixed(1) > Fixed(1)) << std::endl;
	std::cout << "1 < 1 == " << (Fixed(1) < Fixed(1)) << std::endl;
	std::cout << "1 <= 2 == " << (Fixed(1) <= Fixed(2)) << std::endl;
	std::cout << "2 <= 1 == " << (Fixed(2) <= Fixed(1)) << std::endl;
	std::cout << "1 >= 2 == " << (Fixed(1) >= Fixed(2)) << std::endl;
	std::cout << "2 >= 1 == " << (Fixed(2) >= Fixed(1)) << std::endl;
	std::cout << "1 >= 1 == " << (Fixed(1) >= Fixed(1)) << std::endl;
	std::cout << "1 <= 1 == " << (Fixed(1) <= Fixed(1)) << std::endl;
	std::cout << "1 == 1 == " << (Fixed(1) == Fixed(1)) << std::endl;
	std::cout << "1 == 2 == " << (Fixed(1) == Fixed(2)) << std::endl;
	std::cout << "1 != 1 == " << (Fixed(1) != Fixed(1)) << std::endl;
	std::cout << "1 != 2 == " << (Fixed(1) != Fixed(2)) << std::endl;
}

void	testMinMax() {
	Fixed a(1);
	Fixed b(2);
	const Fixed c(a);
	const Fixed d(b);

	std::cout << "a == " << a << ", b == " << b << ", c == " << c << ", d == " << d << std::endl;
	std::cout << "min(a, b) == " << Fixed::min(a,b) << std::endl;
	std::cout << "max(a, b) == " << Fixed::max(a,b) << std::endl;
	std::cout << "min(c, d) == " << Fixed::min(c, d) << std::endl;
	std::cout << "max(c, d) == " << Fixed::max(c, d) << std::endl;
}

int	main() {
	std::cout << "subject example func:" << std::endl << std::endl;
	exampleFunc();

	std::cout << std::endl << "incrementation test:" << std::endl << std::endl;
	testIncrementation();
	std::cout << std::endl << "decrementation test:" << std::endl << std::endl;
	testDecrementation();
	std::cout << std::endl << "addition test:" << std::endl << std::endl;
	testAddition();
	std::cout << std::endl << "subtraction test" << std::endl << std::endl;
	testSubtraction();
	std::cout << std::endl << "multiplication test" << std::endl << std::endl;
	testMultiplication();
	std::cout << std::endl << "division test" << std::endl << std::endl;
	testDivision();
	std::cout << std::endl << "comparison test" << std::endl << std::endl;
	testComparison();
	std::cout << std::endl << "minmax test" << std::endl << std::endl;
	testMinMax();
}
