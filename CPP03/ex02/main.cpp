#include "FragTrap.hpp"

int main()
{
	FragTrap alirio("Alirio");

	for (size_t i = 0; i < 51; i++)
	{
		alirio.beRepaired(0);
		alirio.attack("vitim");
	}
	alirio.highFivesGuys();
}