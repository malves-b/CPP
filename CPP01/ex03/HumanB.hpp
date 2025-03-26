#pragma once

#include "Weapon.hpp"

#define GREEN	"\033[32m"

class HumanB
{
private:
	std::string	name;
	Weapon*		WeaponHB;
public:
	HumanB(std::string name);
	~HumanB();

	void	setWeapon(Weapon &WB);
	void	attack(void);
};
