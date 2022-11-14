#include "../includes/Harl.hpp"

Harl::Harl()
{
	std::cout << "Default constructor called for Harl" << std::endl;
}

Harl::~Harl()
{
	std::cout << "Destructor of Harl called" << std::endl;
}

void	Harl::_debug()
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do !" << std::endl;
}

void	Harl::_info()
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger ! If you did, I wouldn’t be asking for more !" << std::endl;
}

void	Harl::_warning()
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void	Harl::_error()
{
	std::cout << "This is unacceptable ! I want to speak to the manager now." << std::endl;
}

void	Harl::complain(std::string level)
{
	std::string	tab[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	int i = 0;
	while (i < 4 && level != tab[i])
		i++;
	switch (i)
	{
		case 0:
			std::cout << "[DEBUG]" << std::endl;
			this->_debug();
			__attribute__ ((fallthrough));
		case 1:
			std::cout << "[INFO]" << std::endl;
			this->_info();
			__attribute__ ((fallthrough));
		case 2:
			std::cout << "[WARNING]" << std::endl;
			this->_warning();
			__attribute__ ((fallthrough));
		case 3:
			std::cout << "[ERROR]" << std::endl;
			this->_error();
			break;

		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			break;
	}
}
