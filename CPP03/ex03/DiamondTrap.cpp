#include "DiamondTrap.hpp"

//Default constructor
DiamondTrap::DiamondTrap(): ClapTrap("Default_clap_name"), name("Default")
{
	std::cout << "DiamondTrap: Default constructor" << std::endl;
	this->hitPoints = FragTrap::hitPoints;
	this->energyPoints = ScavTrap::energyPoints;
	this->attackDamage = FragTrap::attackDamage;
}

//String constructor
DiamondTrap::DiamondTrap(std::string name): ClapTrap(name + "_clap_name"), name(name) 
{
	this->hitPoints = FragTrap::hitPoints;
	this->energyPoints = ScavTrap::energyPoints;
	this->attackDamage = FragTrap::attackDamage;
	std::cout << "DiamondTrap: string constructor" << std::endl;
}

//Destructor
DiamondTrap::~DiamondTrap(){std::cout << "DiamondTrap: " << this->name << " Destroyed" << std::endl;}

//Copy constructor
DiamondTrap::DiamondTrap(const DiamondTrap &original): ClapTrap(original), ScavTrap(original), FragTrap(original)
{
	std::cout << "DiamondTrap: Copy constructor" << std::endl;
    *this = original;
}

//Operator overload
DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other)
{
	std::cout << "DiamondTrap: Operator overload" << std::endl;
	if (this != &other){
		ClapTrap::operator=(other);
		this->name = other.name;
		this->energyPoints = other.energyPoints;
		this->attackDamage = other.attackDamage;
		this->hitPoints = other.hitPoints;
	}
	return *this;
}

void DiamondTrap::whoAmI()
{
	std::cout << "I am " << this->name << ", and my ClapTrap name is " << ClapTrap::name << "." << std::endl;
}
