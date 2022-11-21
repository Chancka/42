#include "../includes/Contact.hpp"

Contact::Contact()
{
	std::cout << "Default constructor called for Contact" << std::endl;
}

Contact::~Contact()
{
	std::cout << "Destructor of Contact called" << std::endl;
}

int	Contact::is_full(void)
{
	if (!this->_first_name.empty())
		return (1);
	return (0);
}

void	Contact::erase_contact(void)
{
	this->_first_name.clear();
	this->_last_name.clear();
	this->_nickname.clear();
	this->_phone_number.clear();
	this->_secret.clear();
}

void	Contact::new_contact(void)
{
	while (this->_first_name.empty())
	{
		std::cout << "What's the first name ?" << std::endl;
		std::getline(std::cin, this->_first_name);
	}
	while (this->_last_name.empty())
	{
		std::cout << "What's the last name ?" << std::endl;
		std::getline(std::cin, this->_last_name);
	}
	while (this->_nickname.empty())
	{
		std::cout << "What's the nickname ?" << std::endl;
		std::getline(std::cin, this->_nickname);
	}
	while (this->_phone_number.empty())
	{
		std::cout << "What's the phone number ?" << std::endl;
		std::getline(std::cin, this->_phone_number);
	}
	while (this->_secret.empty())
	{
		std::cout << "What's the darkest secret ?" << std::endl;
		std::getline(std::cin, this->_secret);
	}
}

void	Contact::display_contact(void)
{
	std::cout << "First name : " << _first_name << std::endl;
	std::cout << "Last name : " << _last_name << std::endl;
	std::cout << "Nickname : " <<_nickname << std::endl;
	std::cout << "Phone number : " << _phone_number << std::endl;
	std::cout << "Darkest secret : " << _secret << std::endl;
}

void	Contact::_print_string(std::string str)
{
	std::cout << std::setw(10);
	if (str.length() > 10)
		str = str.substr(0, 9) + ".";
	std::cout << str << "|";
}

void	Contact::display_identify(void)
{
	_print_string(this->_first_name);
	_print_string(this->_last_name);
	_print_string(this->_nickname);
	std::cout << std::endl;
}
