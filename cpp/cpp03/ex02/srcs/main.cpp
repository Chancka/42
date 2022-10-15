#include "../includes/FragTrap.hpp"

int main(int ac, char **av)
{
	FragTrap	chancka("Chancka");
	FragTrap	test(chancka);


	chancka.attack("ennemy");
	chancka.takeDamage(100);
	chancka.beRepaired(100);
	chancka.guardGate();
	chancka.highFivesGuys();

	test.attack("ennemy");
	test.takeDamage(100);
	test.beRepaired(100);
	test.guardGate();
	test.highFivesGuys();

	return (0);	
}
