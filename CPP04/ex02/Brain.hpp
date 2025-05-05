#include <iostream>
#include <string>

class Brain
{
protected:
	std::string ideas[100];
public:
	Brain();
	Brain(Brain& cpy);
	Brain& operator=(const Brain &other);
	~Brain();
};
