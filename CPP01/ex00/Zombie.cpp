#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
	this->name = name;
}

Zombie::~Zombie(){
	std::cout << this->name << " destroyed.\n";
}

void	Zombie::announce(void){
	std::cout << this->name << ": " << "BraiiiiiiinnnzzzZ...";
}

