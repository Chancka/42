#include "../includes/PhoneBook.hpp"
#include "../includes/Contact.hpp"

int main(int ac, char **av)
{
	PhoneBook	phonebook;
	std::string	input;
	int			i = 0;

	while (1)
	{
		std::cout << "Do you want to ADD, SEARCH or EXIT ?" << std::endl;
		std::getline(std::cin, input);
		if (input == "ADD")
		{
			if (i == 8)
				i = 0;
			phonebook.add_contact(i);
			i++;
		}
		if (input == "SEARCH")
		{
			phonebook.display_contacts();
			std::cout << "Enter a number between 1 and 8" << std::endl;
			std::getline(std::cin, input);
			if (input != "" && (std::stoi(input) < 9 && std::stoi(input) > 0))
				phonebook.display_one_contact(std::stoi(input) - 1);
			else
				std::cout << "Not a valid argument" << std::endl;
		}
		if (input == "EXIT")
			return (0);
	}
	return (0);	
}
