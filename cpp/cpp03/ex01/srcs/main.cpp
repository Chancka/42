#include "../includes/ScavTrap.hpp"

int main(int ac, char **av)
{
	ScavTrap	chancka("Chancka");
	ScavTrap	test;

	chancka.attack("ennemy");
	chancka.takeDamage(100);
	chancka.beRepaired(100);
	chancka.guardGate();

	test.attack("ennemy");
	test.takeDamage(100);
	test.beRepaired(100);
	test.guardGate();

	return (0);	
}
