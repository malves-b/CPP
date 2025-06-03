#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

//default constructor
RobotomyRequestForm::RobotomyRequestForm(): AForm("default", 72, 45), _target("default"){}

//Parametized constructor
RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm(target, 72, 45), _target(target){}

//Copy constructor
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &cpy){*this = cpy;return;}

//Destructor
RobotomyRequestForm::~RobotomyRequestForm(){}

//Assignment operator
RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	if (this != &other)
		this->_target = other._target;
	return *this;	
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (!this->getIsSigned())
		throw FormNotSignedException();
	if (executor.getGrade() > this->getExeGrade())
		throw GradeTooLowException();

	std::cout << "** Drilling noises **" << std::endl;
	std::srand(std::time(0));
	if (rand() % 2 == 0)
		std::cout << green << "Robotomy succeeded!" << reset << std::endl;
	else
		std::cout << red << "Robotomy failed" << reset << std::endl;
}
