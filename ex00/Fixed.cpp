#include <iostream>

#include "Fixed.hpp"

Fixed::Fixed() {
	std::cerr << "default constructor called" << std::endl;

	this->rawBits = 0;
}

Fixed::Fixed(const Fixed& other) {
	std::cerr << "copy constructor called" << std::endl;

	this->rawBits = other.rawBits;
}

Fixed& Fixed::operator =(const Fixed& other) {
	std::cerr << "copy assignment operator called" << std::endl;

	if (this == &other) return *this;
	this->rawBits = other.rawBits;
	return *this;
}

Fixed::~Fixed() {
	std::cerr << "destructor called" << std::endl;
}

int	Fixed::getRawBits(void) const {
	std::cerr << "member function getRawBits called" << std::endl;

	return this->rawBits;
}

void	Fixed::setRawBits(const int raw) {
	std::cerr << "member function setRawBits called" << std::endl;

	this->rawBits = raw;
}
