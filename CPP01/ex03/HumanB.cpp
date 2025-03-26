#include "HumanB.hpp"

void	HumanB::setWeapon(Weapon &WB){this->WeaponHB = &WB;}

HumanB::HumanB(std::string name): name(name), WeaponHB(NULL){}

HumanB::~HumanB(){}

void	HumanB::attack(void){
	std::cout << GREEN << this->name << " attacks with their: " 
	<< this->WeaponHB->getType() << std::endl;
}