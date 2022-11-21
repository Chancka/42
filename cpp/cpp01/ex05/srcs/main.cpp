#include "../includes/Harl.hpp"

int main(void)
{
	Harl		harl;
	std::string	input;

	std::cout << "Choose between : DEBUG, INFO, WARNING or ERROR" << std::endl;
	std::cin >> input;
	harl.complain(input); // call the complain function with the string passed as argument
	return (0);	
}
