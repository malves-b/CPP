#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void)
{
	this->name = "Default";
	this->hitPoints = 10;
	this->energyPoints = 10;
	this->attackDamage = 0;
	std::cout << "Default constructor called!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &cpy){std::cout << "Copy constructor called!" << std::endl;*this = cpy;}

ClapTrap	&ClapTrap::operator=(const ClapTrap &other) {
	std::cout << "Operator Overload called" << std::endl;
	if (this != &other)
	{
		this->name = other.name;
		this->hitPoints = other.hitPoints;
		this->energyPoints = other.energyPoints;
		this->attackDamage = other.attackDamage;
	}
	return *this;
}

ClapTrap::ClapTrap(std::string name)
{
	this->name = name;
	this->hitPoints = 10;
	this->energyPoints = 10;
	this->attackDamage = 0;
	std::cout << "Constructor called!" << std::endl;
}

ClapTrap::~ClapTrap(){std::cout << this->name <<" Destroyed" << std::endl;}

void	ClapTrap::attack(const std::string &target)
{
	if (energyPoints < 1)
		std::cout << yellow << name << " don't have enough energy points" << reset << std::endl;
	else
	{
		energyPoints--;
		std::cout << red << "Claptrap " <<this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << reset << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	this->hitPoints -= amount;
	std::cout << this->name << " taked " << amount << "damage" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	this->energyPoints--;
	if (energyPoints < 1)
		std::cout << yellow << name << " don't have enough energy points" << reset << std::endl;
	else{
		this->hitPoints += amount;
		std::cout << green << this->name << " Repeired " << amount << " hitpoints" << reset << std::endl;}
}

std::string ClapTrap::getName(void){return this->name;}

void	ClapTrap::setName(std::string name){this->name = name;}
