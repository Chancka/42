#include "../includes/PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	std::cout << "Default constructor called for PhoneBook" << std::endl;
}

PhoneBook::~PhoneBook()
{
	std::cout << "Destructor of PhoneBook called" << std::endl;
}

void	PhoneBook::add_contact(int i)
{
	if (this->_contact[i].is_full())
		this->_contact[i].erase_contact();
	this->_contact[i].new_contact();
}

void	PhoneBook::display_one_contact(int i)
{
	this->_contact[i].display_contact();
}

void	PhoneBook::display_contacts(void) {

	int	i = 0;
	std::cout << "     ================================ " << std::endl;
	std::cout << "    |          |          |          |" << std::endl;
	std::cout << "    |FIRST_NAME| LAST_NAME| NICKNAME |" << std::endl;
	std::cout << " ___|__________|__________|__________|" << std::endl;
	while (i < 8)
	{
		std::cout << "|" << std::setw(3) << i + 1 << "|";
		this->_contact[i].display_identify();
		std::cout << std::endl;
		i++;
	}
	std::cout << " ===================================== " << std::endl << std::endl;
}
