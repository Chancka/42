#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <string>
#include <iomanip>
class Contact
{
	public:

	Contact();
	~Contact();

	int		is_full(void);
	void	erase_contact(void);
	void	new_contact(void);
	void	display_contact(void);
	void	display_identify(void);

	private:

	void	print_string(std::string str);
	std::string	_first_name;
	std::string	_last_name;
	std::string	_nickname;
	std::string	_phone_number;
	std::string	_secret;

};

#endif
