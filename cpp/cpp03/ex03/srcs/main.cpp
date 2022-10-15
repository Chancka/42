#include "../includes/DiamondTrap.hpp"

int main(int ac, char **av)
{
	DiamondTrap	chancka("Chancka");

	chancka.attack("ennemy");
	chancka.takeDamage(10);
	chancka.beRepaired(10);
	chancka.guardGate();
	chancka.highFivesGuys();
	chancka.whoAmI();

	return (0);	
}
