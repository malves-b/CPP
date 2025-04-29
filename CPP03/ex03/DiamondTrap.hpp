#include "FragTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
private:
	std::string name;
public:
	DiamondTrap();
	~DiamondTrap();
	DiamondTrap(const DiamondTrap &original);
	DiamondTrap &operator=(const DiamondTrap &other);
	DiamondTrap(std::string name);

	void whoAmI();
	using ScavTrap::attack;
};
