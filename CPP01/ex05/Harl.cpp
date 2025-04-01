#include "Harl.hpp"

void Harl::debug(void)
{
	std::cout << green << " ----- Debug ----- \n" << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketup burger. I really do!" << RESET << std::endl;
}

void Harl::info(void)
{
	std::cout << yellow << "----- Info -----\n" << "I cannot believe adding extra bacon costs more money. You did'nt put enough bacon in my burger! If you did, I wouldn't be asking for more!" << RESET <<std::endl;
}

void Harl::warning(void)
{
	std::cout << blue << "----- Warning -----" << "I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month." << std::endl;
}

void Harl::error(void)
{
	std::cout << red << "----- Error -----\n" << "This is unacceptable! I want to speak to the manager now." << RESET << std::endl;
}

Harl::Harl(){}
Harl::~Harl(){};

void	Harl::complain(std::string level)
{
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*func[4])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	for (size_t i = 0; i < 4; i++)
	{
		if (level == levels[i])
		{
			(this->*func[i])();
			return ;
		}
	}
	std::cout << "Invalid level!" << std::endl;
}
