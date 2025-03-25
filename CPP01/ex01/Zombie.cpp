#include "Zombie.hpp"

int	index = 0;

Zombie::Zombie(void){
	std::cout << green << "--- " << name << index << "Created ---\n" << RESET;
	index++;
}

Zombie::~Zombie(){
	std::cout << red << "--- " << name << " Destroyed ---\n" << RESET << std::endl;
}

void	Zombie::set_name(std::string name){this->name = name;}

void	Zombie::announce(){
	std::cout << yellow << name << ": Braiiiiiiinnnzzz\n" << RESET << std::endl;
}

