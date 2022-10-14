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
	Fixed &operator=(const Fixed &other);
	~Fixed();
	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	int		toInt() const;
	float	toFloat() const;

	private:

	int					_nb_fixed;
	static	const	int	_bits = 8;
};

std::ostream	&operator<<(std::ostream &o, Fixed const &rhs);

#endif
