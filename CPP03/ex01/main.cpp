#include "ScavTrap.hpp"

int main()
{
	ScavTrap scav("Alirio");

	scav.attack("vitm");
	scav.takeDamage(20);
	scav.beRepaired(10);
	scav.guardGate();

	for (size_t i = 0; i < 26; i++)
	{
		scav.attack("sla");
		scav.beRepaired(5);
	}
	scav.guardGate();
	return 0;
}
