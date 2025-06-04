#include "Intern.hpp"

Intern::Intern(){}

Intern::Intern(const Intern &cpy){*this = cpy;}

Intern &Intern::operator=(const Intern &) { return *this;}

Intern::~Intern(){}

AForm* makeShrubberyForm(std::string target){
	return (new ShrubberyCreationForm(target));
}

AForm* makePresidentialForm(std::string target){
	return (new PresidentialPardonForm(target));
}

AForm* makeRobotomyForm(std::string target){
	return (new RobotomyRequestForm(target));
}

AForm *Intern::makeForm(std::string formName, std::string target)
{
	AForm* (*Func[3])(std::string target) = {&makeShrubberyForm, &makePresidentialForm, &makeRobotomyForm};
	std::string forms[] = {"shrubbery creation", "presidential pardon", "robotomy request"};
	for (int i = 0; i < 3; i++)
	{
		if (formName == forms[i])
			return (Func[i](target));
	}
	throw NotFoundException(formName);
}

Intern::NotFoundException::NotFoundException(const std::string& formName){
	_message = "Intern couldn't find the form named: " + formName;
}

const char *Intern::NotFoundException::what() const throw(){return _message.c_str();}