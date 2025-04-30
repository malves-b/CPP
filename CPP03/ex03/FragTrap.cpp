#include "FragTrap.hpp"

//Default constructor
FragTrap::FragTrap(void) : ClapTrap()
{
	std::cout << "FragTrap: Default constructor" << std::endl;
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
}

//String constructor
FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << "FragTrap: String constructor" << std::endl;
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
}

//Operator overload
FragTrap &FragTrap::operator=(const FragTrap &other)
{
	if (this != &other)
		ClapTrap::operator=(other);
	return *this;
}

//Copy constructor
FragTrap::FragTrap(const FragTrap &cpy): ClapTrap(cpy) {std::cout << "FragTrap: Copy constructor called!" << std::endl;*this = cpy;}

//Destructor
FragTrap::~FragTrap(){std::cout << red << "FragTrap: " << name << " Destroyed" << reset << std::endl;}

void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap: High Five!" << std::endl;
}
