#ifndef TYPE_HPP
# define TYPE_HPP

# include <iostream>
# include <stdexcept>
# include <climits>
# include <cfloat>
# include <iomanip>
# include <cstdlib>

class Type
{
	public:
		Type();
		Type(Type const & src);
		~Type();

		Type & operator=(Type const & rhs);

		void    setChar(std::string s);
		void    setInt(std::string s);
		void    setFloat(std::string s);
		void    setDouble(std::string s);
		void	setString(std::string s);
		void	setAll(std::string s);

		char    getChar() const;
		int     getInt() const;
		float   getFloat() const;
		double  getDouble() const;
		std::string getString() const;

		void    printChar() const;
		void    printInt() const;
		void    printFloat() const;
		void    printDouble() const;

	private:
		char		_c;
		long int	_i;
		double		_f;
		long double	_d;
		std::string	_s;
};

#endif

