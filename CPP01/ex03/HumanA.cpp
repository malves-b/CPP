#include "HumanA.hpp"

void	HumanA::attack(void){
	std::cout << RED << this->name << " attacks with their: " 
	<< this->WeaponHA.getType() << std::endl;
}

HumanA::HumanA(std::string name, Weapon& HA): name(name), WeaponHA(HA){}

HumanA::~HumanA(){}
