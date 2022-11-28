#include "../includes/FragTrap.hpp"

int main(void)
{
	FragTrap	chancka("Chancka");
	FragTrap	test(chancka);


	chancka.attack("ennemy");
	chancka.takeDamage(100);
	chancka.beRepaired(100);
	chancka.highFivesGuys();

	test.attack("ennemy");
	test.takeDamage(100);
	test.beRepaired(100);
	test.highFivesGuys();

	return (0);	
}
