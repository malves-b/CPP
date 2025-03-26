#include "Weapon.hpp"

const	std::string	Weapon::getType() const {return (this->type);}

void	Weapon::setType(std::string type){this->type = type;}

Weapon::Weapon(){return;}
Weapon::Weapon(std::string type){this->type = type;}
Weapon::~Weapon(){};
