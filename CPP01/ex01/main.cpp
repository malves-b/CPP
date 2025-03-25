#include "Zombie.hpp"

int main(void)
{
	Zombie *horde = zombieHorde(7, "Alirio");
	if (horde)
	{
		for (int i = 0; i < 7; i++)
			horde[i].announce();
	}
	delete []horde;
	return 0;
}
