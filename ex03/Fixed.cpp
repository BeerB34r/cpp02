#include <cmath>
#include <iomanip>
#include <iostream>

#include "Fixed.hpp"

int	pow(int base, int exponent) {
	int	result = 1;
	for (int i = 0; i < exponent; i++) result *= base;

	return result;
}

const int	Fixed::fractionalPrecision = pow(2, Fixed::fractionalBits);

Fixed::Fixed() {
	std::cerr << "default constructor called" << std::endl;

	this->rawBits = 0;
}

Fixed::Fixed(const int num) {
	std::cerr << "integer constructor called" << std::endl;

	this->rawBits = num << fractionalBits;
}

Fixed::Fixed(const float num) {
	std::cerr << "float constructor called" << std::endl;
	if (num < 0) {
		std::cerr << "this implementation of fixed point numbers does not currently support signed numbers. your mileage may vary" << std::endl;
	}

	this->rawBits = std::roundf(num * fractionalPrecision);
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

float	Fixed::toFloat() const {
	float out = this->rawBits;
	return out / fractionalPrecision;
}

int	Fixed::toInt() const {
	return this->rawBits >> fractionalBits;
}

Fixed&	Fixed::operator++() {
	this->rawBits++;
	return *this;
}

Fixed	Fixed::operator++(int) {
	Fixed	old = *this;
	operator++();
	return old;
}

Fixed&	Fixed::operator--() {
	this->rawBits--;
	return *this;
}

Fixed	Fixed::operator--(int) {
	Fixed old = *this;
	operator--();
	return old;
}

std::ostream& operator <<(std::ostream& out, const Fixed& fixed) {
	out << fixed.toFloat();
	return out;
}

bool operator <(const Fixed& a, const Fixed& b) {
	return a.getRawBits() < b.getRawBits();
}

bool operator >(const Fixed& a, const Fixed& b) {
	return a.getRawBits() > b.getRawBits();
}

bool operator >=(const Fixed& a, const Fixed& b) {
	return !(a < b);
}

bool operator <=(const Fixed& a, const Fixed& b) {
	return !(a > b);
}

bool operator ==(const Fixed& a, const Fixed& b) {
	return a.getRawBits() == b.getRawBits();
}

bool operator !=(const Fixed& a, const Fixed& b) {
	return !(a == b);
}

Fixed operator +(const Fixed& a, const Fixed& b) {
	Fixed out;
	out.setRawBits( a.getRawBits() + b.getRawBits());
	return out;
}

Fixed operator -(const Fixed& a, const Fixed& b) {
	Fixed out;
	out.setRawBits( a.getRawBits() - b.getRawBits());
	return out;
}

Fixed operator *(const Fixed& a, const Fixed& b) {
	return Fixed(a.toFloat() * b.toFloat());
}

Fixed operator /(const Fixed& a, const Fixed& b) {
	if (b == 0) throw std::domain_error("cannot divide by zero");
	return Fixed(a.toFloat() / b.toFloat());
}

Fixed&	Fixed::min(Fixed& a, Fixed& b) {
	return a < b ? a : b;
}

const Fixed&	Fixed::min(const Fixed& a, const Fixed& b) {
	return a < b ? a : b;
}

Fixed&	Fixed::max(Fixed& a, Fixed& b) {
	return a > b ? a : b;
}

const Fixed&	Fixed::max(const Fixed& a, const Fixed& b) {
	return a > b ? a : b;
}
