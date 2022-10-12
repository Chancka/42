#include "../includes/replace.hpp"

int main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cout << "Wrong arguments" << std::endl;
		return (0);
	}
	replace(av[1], av[2], av[3]);
	return (0);
}
