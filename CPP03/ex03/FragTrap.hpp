#include "ScavTrap.hpp"

class FragTrap : virtual public ClapTrap
{
public:
	FragTrap();
	FragTrap(std::string name);
	FragTrap(const FragTrap &cpy);

	FragTrap &operator=(const FragTrap &other);

	~FragTrap();

	void	highFivesGuys(void);
};

