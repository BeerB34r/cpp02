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
private:
	long long	rawBits;
	static const int	fractionalBits = 8;
	static const int	fractionalPrecision;
protected:
};

std::ostream& operator <<(std::ostream&, const Fixed&);

#endif // FIXED_HPP
