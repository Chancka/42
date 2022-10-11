#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include "../includes/Contact.hpp"

class PhoneBook
{
	public:

	PhoneBook();
	~PhoneBook();

	void	add_contact(int i);
	void	display_one_contact(int i);
	void	display_contacts();

	private:

	Contact _contact[8];
	
};

#endif
