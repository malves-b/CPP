#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap	alirio("alirio");

	for (size_t i = 0; i < 11; i++)
	{
		alirio.attack("victim");
		alirio.beRepaired(5);
	}
	alirio.beRepaired(5);
	return 0;
}
