#include "Harl.hpp"

Harl::Harl(void){}
Harl::~Harl(){}

void	Harl::debug(void){
	std::cout << blue << "[ DEBUG ]\n" << RESET << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!"<< std::endl;
}

void	Harl::info(void){
	std::cout << green << "[ INFO ]\n" << RESET << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void	Harl::warning(void){
	std::cout << yellow << "[ WARNING ]\n" << RESET << "I think I deserve to have some extra bacon for free.\nI've been coming for years, whereas you started working here just last month." << std::endl;
}

void	Harl::error(void){
	std::cout << red << "[ ERROR ]\n" << RESET << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void	Harl::complain(std::string level)
{
	std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int index = -1;

	for (size_t i = 0; i < 4; i++){
		if (levels[i] == level){
			index = i;
			break;
		}
	}
	switch (index)
	{
		case 0:
			debug();	
		case 1:
			info();
		case 2:
			warning();
		case 3:
			error();
			break;
		default:
			std::cout << yellow << "[ Probably complaining about insignificant problems ]" << std:: endl;
	}
}
