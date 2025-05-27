#pragma once

#include "Bureaucrat.hpp"

class ShrubberyCreationForm : public Form
{
private:
	std::string _target;
public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(std::string target);
	ShrubberyCreationForm(ShrubberyCreationForm &cpy);
	~ShrubberyCreationForm();

	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);

};
