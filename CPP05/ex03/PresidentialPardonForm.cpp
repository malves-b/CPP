#include "PresidentialPardonForm.hpp"

//Default constructor
PresidentialPardonForm::PresidentialPardonForm(): AForm("default", 25, 5), _target("default"){}

//Parametized constructor
PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm("PresidentialPardonForm", 25, 5), _target(target){}

//Copy constructor
PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm &cpy){*this = cpy;}

//Destructor
PresidentialPardonForm::~PresidentialPardonForm(){}

//Assignment operator
PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	if (this != &other)
		this->_target = other._target;
	return *this;	
}

void	PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (!this->getIsSigned())
		throw FormNotSignedException();
	if (executor.getGrade() > this->getExeGrade())
		throw GradeTooLowException();
	std::cout << this->_target << "has been pardoned by Zaphod Beeblebrox." << std::endl;
}
