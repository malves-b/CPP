#pragma once

#include <iostream>
#include <string>

class ClapTrap
{
private:
	std::string name;
	int	hit_points = 10;
public:
	ClapTrap(/* args */);
	~ClapTrap();
};
