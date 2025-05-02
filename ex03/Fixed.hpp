#ifndef FIXED_HPP
# define FIXED_HPP

#include <ostream>

class	Fixed {
public:
	Fixed();
	Fixed(const int);
	Fixed(const float);
	Fixed(const Fixed&);
	Fixed& operator =(const Fixed&);
	~Fixed();

	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	float	toFloat(void) const;
	int		toInt(void) const;

	Fixed&	operator++();
	Fixed	operator++(int);
	Fixed&	operator--();
	Fixed	operator--(int);

	static Fixed& min(Fixed&, Fixed&);
	static const Fixed& min(const Fixed&, const Fixed&);
	static Fixed& max(Fixed&, Fixed&);
	static const Fixed& max(const Fixed&, const Fixed&);
private:
	long long	rawBits;
	static const int	fractionalBits = 8;
	static const int	fractionalPrecision;
protected:
};

std::ostream& operator <<(std::ostream&, const Fixed&);
bool operator <(const Fixed&, const Fixed&);
bool operator >(const Fixed&, const Fixed&);
bool operator <=(const Fixed&, const Fixed&);
bool operator >=(const Fixed&, const Fixed&);
bool operator ==(const Fixed&, const Fixed&);
bool operator !=(const Fixed&, const Fixed&);

Fixed operator +(const Fixed&, const Fixed&);
Fixed operator -(const Fixed&, const Fixed&);
Fixed operator *(const Fixed&, const Fixed&);
Fixed operator /(const Fixed&, const Fixed&);

#endif // FIXED_HPP
