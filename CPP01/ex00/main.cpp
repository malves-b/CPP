#include "Zombie.hpp"

int	main(void)
{
	Zombie* z1 = newZombie("z1");//Heap
	z1->announce();
	delete z1;
	randomChump("StackZombie");	 //stack
	return (0);
}
