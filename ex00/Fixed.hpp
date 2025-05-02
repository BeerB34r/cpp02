#ifndef FIXED_HPP
# define FIXED_HPP

class	Fixed {
public:
	Fixed();
	Fixed(const Fixed&);
	Fixed& operator =(const Fixed&);
	~Fixed();

	int	getRawBits(void) const;
	void setRawBits(int const raw);
private:
	int	rawBits;
	static const int	fractionalBits = 8;
protected:
};

#endif // FIXED_HPP
