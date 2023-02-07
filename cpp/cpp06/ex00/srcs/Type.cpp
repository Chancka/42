#include "../includes/Type.hpp"

Type::Type()
{
	std::cout << "Type default constructor called" << std::endl;
}

Type::Type(Type const & src)
{
	std::cout << "Type copy constructor called" << std::endl;
	*this = src;
}

Type::~Type()
{
	std::cout << "Type destructor called" << std::endl;
}

Type & Type::operator=(Type const & rhs)
{
	std::cout << "Type assignation operator called" << std::endl;
	if (this != &rhs)
	{
		this->_c = rhs.getChar();
		this->_i = rhs.getInt();
		this->_f = rhs.getFloat();
		this->_d = rhs.getDouble();
	}
	return *this;
}

void    Type::setChar(std::string s)
{
	this->_c = s[0];
}

void    Type::setInt(std::string s)
{
	this->_i = static_cast<long int>(std::atol(s.c_str()));
}

void    Type::setFloat(std::string s)
{
	this->_f = static_cast<float>(atof(s.c_str()));
}

void    Type::setDouble(std::string s)
{
	this->_d = static_cast<double>(atof(s.c_str()));
}

void	Type::setString(std::string s)
{
	this->_s = s;
}

void	Type::setAll(std::string s)
{
	this->setChar(s);
	this->setInt(s);
	this->setFloat(s);
	this->setDouble(s);
	this->setString(s);
}

char    Type::getChar() const
{
	return this->_c;
}

int     Type::getInt() const
{
	return this->_i;
}

float   Type::getFloat() const
{
	return this->_f;
}

double  Type::getDouble() const
{
	return this->_d;
}

std::string Type::getString() const
{
	return this->_s;
}

void    Type::printChar() const
{
	std::cout << "char: ";
	if (this->_s.find('.') != std::string::npos && this->_s[this->_s.length() - 1] == 'f')
		std::cout << "'*'" << std::endl;
	else if (this->_s.find("nan") != std::string::npos || this->_s.find("inf") != std::string::npos)
		std::cout << "impossible" << std::endl;
	else if (this->_s.length() == 1 && isprint(this->_c) && !isdigit(this->_c))
		std::cout << "'" << this->_s << "'" << std::endl;
	else
		std::cout << "Non displayable" << std::endl;
}

void    Type::printInt() const
{
	std::cout << "int: "; 
	if (this->_s == "nanf" || this->_s == "nan" || this->_s == "inf" || this->_s == "-inf")
		std::cout << "impossible" << std::endl;
	else if (this->_i >= INT_MIN && this->_i <= INT_MAX)
		std::cout << this->_i << std::endl;
	else
		std::cout << "impossible" << std::endl;
}

void    Type::printFloat() const
{
	std::cout << "float: ";
	if (this->_s == "nanf" || this->_s == "nan" || this->_s == "inf" || this->_s == "-inf")
		std::cout << "nanf" << std::endl;
	else if (atof(this->_s.c_str()) >= -FLT_MAX && atof(this->_s.c_str()) <= FLT_MAX)
		std::cout << std::fixed << std::setprecision(1) << (float)this->_f << "f" << std::endl;
	else
		std::cout << "impossible" << std::endl;
}

void    Type::printDouble() const
{
	std::cout << "double: ";
	if (this->_s == "nanf" || this->_s == "nan" || this->_s == "inf" || this->_s == "-inf")
		std::cout << "nan" << std::endl;
	else if (this->_d >= -DBL_MAX && this->_d <= DBL_MAX)
		std::cout << std::fixed << std::setprecision(1) << this->_d << std::endl;	
	else
		std::cout << "impossible" << std::endl;
}
