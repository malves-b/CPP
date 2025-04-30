#include "ScavTrap.hpp"

//Default constructor
ScavTrap::ScavTrap(void) : ClapTrap()
{
	std::cout << "ScavTrap: Default constructor" << std::endl;
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
}

//String constructor
ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "ScavTrap: String constructor" << std::endl;
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
}

//Operator overload
ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
	if (this != &other)
		ClapTrap::operator=(other);
	return *this;
}

//Copy constructor
ScavTrap::ScavTrap(const ScavTrap &cpy): ClapTrap(cpy) {std::cout << "ScavTrap: Copy constructor called!" << std::endl;*this = cpy;}

//Destructor
ScavTrap::~ScavTrap(){std::cout << red << "ScavTrap: " << name << " Destroyed" << reset << std::endl;}

void ScavTrap::attack(const std::string& target)
{
	if (hitPoints <= 0 || energyPoints <= 0)
	{
		std::cout << yellow << "ScavTrap: " << name << " cannot attack!" << reset << std::endl;
		return;
	}
	energyPoints--;
	std::cout << blue << "ScavTrap: " << name << " slashes " << target << " for " << attackDamage << " points of damage!" << reset << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap: " << name << " has entered Gate keeper mode." << std::endl;
}
