#pragma once

#include "Weapon.hpp"

#define RED		"\033[31m"

class HumanA
{
private:
	std::string	name;
	Weapon&		WeaponHA;
public:
	HumanA(std::string name, Weapon& HA);
	~HumanA();

	void	attack(void);
};

