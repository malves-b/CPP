#pragma once

#include <iostream>
#include <string>
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
public:
	ScavTrap(void);
	ScavTrap(std::string name);
	ScavTrap(const ScavTrap &cpy);

	ScavTrap &operator=(const ScavTrap &other);

	~ScavTrap();

	void	attack(const std::string& target);
	void	guardGate();
};


