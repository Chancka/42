#include "../includes/Harl.hpp"

int main(int ac, char **av)
{
	Harl		harl;
	std::string	input;

	std::cout << "Choose between : DEBUG, INFO, WARNING or ERROR" << std::endl;
	std::cin >> input;
	harl.complain(input);
	return (0);	
}
