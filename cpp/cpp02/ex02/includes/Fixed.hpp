#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <string>
#include <cmath>

class Fixed
{
	public:

	Fixed();
	Fixed(const int nb_int);
	Fixed(const float nb_float);
	Fixed(const Fixed &other);
	Fixed	&operator=(const Fixed &rhs);
	bool	operator>(const Fixed &rhs) const;
	bool	operator<(const Fixed &rhs) const;
	bool	operator>=(const Fixed &rhs) const;
	bool	operator<=(const Fixed &rhs) const;
	bool	operator==(const Fixed &rhs) const;
	bool	operator!=(const Fixed &rhs) const;
	Fixed	operator+(const Fixed &rhs) const;
	Fixed	operator-(const Fixed &rhs) const;
	Fixed	operator*(const Fixed &rhs) const;
	Fixed	operator/(const Fixed &rhs) const;
	Fixed	&operator++();
	Fixed	operator++(int);
	Fixed	&operator--();
	Fixed	operator--(int);
	~Fixed();
	int			getRawBits(void) const;
	void		setRawBits(int const raw);
	int			toInt() const;
	float		toFloat() const;
	static const Fixed	&min(const Fixed &a, const Fixed &b);
	static const Fixed	&max(const Fixed &a, const Fixed &b);
	static Fixed		&min(Fixed &a, Fixed &b);
	static Fixed		&max(Fixed &a, Fixed &b);

	private:

	int					_nb_fixed;
	static	const	int	_bits = 8;
};

std::ostream	&operator<<(std::ostream &o, Fixed const &rhs);

#endif
