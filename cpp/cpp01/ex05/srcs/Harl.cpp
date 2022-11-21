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
	std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger ! If you did, I wouldn't be asking for more !" << std::endl;
}

void	Harl::_warning()
{
	std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month." << std::endl;
}

void	Harl::_error()
{
	std::cout << "This is unacceptable ! I want to speak to the manager now." << std::endl;
}

void	Harl::complain(std::string level)
{
	void		(Harl::*pf[4])(void) = {&Harl::_debug, &Harl::_info, &Harl::_warning, &Harl::_error}; // array of pointers to member functions
	std::string	tab[4] = {"DEBUG", "INFO", "WARNING", "ERROR"}; // array of strings

	for (int i = 0; i < 4; i++) // loop through the array of strings
	{
		if (tab[i] == level) // if the string in the array is equal to the string passed as argument
			(this->*pf[i])(); // call the function in the array of pointers
	}
}
