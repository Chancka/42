#include "../includes/ClapTrap.hpp"

int main(void)
{
	ClapTrap	chancka("Chancka");

	chancka.attack("ennemy");
	chancka.takeDamage(5);
	chancka.beRepaired(5);
	chancka.takeDamage(10);
	chancka.beRepaired(1);

	ClapTrap	chancka_copy(chancka);
	ClapTrap	chancka_copy2;
	chancka_copy2 = chancka;

	chancka_copy.beRepaired(1);
	chancka_copy.takeDamage(1);
	chancka_copy2.beRepaired(1);
	chancka_copy2.takeDamage(1);

	ClapTrap	chancka_default;

	for (int i; i < 11; i++)
		chancka_default.attack("ennemy");
	chancka_default.beRepaired(1);
	return (0);	
}
