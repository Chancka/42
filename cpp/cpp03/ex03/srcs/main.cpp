#include "../includes/DiamondTrap.hpp"

int main(void)
{
	DiamondTrap	chancka("Chancka");

	chancka.attack("ennemy");
	chancka.takeDamage(10);
	chancka.beRepaired(10);
	chancka.guardGate();
	chancka.highFivesGuys();
	chancka.whoAmI();
	chancka.takeDamage(100);
	
	DiamondTrap	test;

	test = chancka;
	test.attack("ennemy");
	test.takeDamage(10);
	test.beRepaired(10);
	test.guardGate();
	test.highFivesGuys();
	test.whoAmI();

	return (0);	
}
