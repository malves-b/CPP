#include "ShrubberyCreationForm.hpp"

//Default constructor
ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Default", 145, 137), _target("default"){}

//Parametized constructor
ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target){}

//Copy constructor
ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm &cpy){*this = cpy;return;}

//Destructor
ShrubberyCreationForm::~ShrubberyCreationForm(){}

//Assignment operator
ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if (this == &other)
		return *this;
	_target = other._target;
	return *this;
}

std::string ShrubberyCreationForm::getTarget(){return this->_target;}

#include <fstream>

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (!this->getIsSigned())
		throw FormNotSignedException();
	if (executor.getGrade() > this->getExeGrade())
		throw GradeTooLowException();

	std::ofstream file;
	std::string filename = this->_target + "_shrubbery";

	file.open(filename.c_str());
	if (file.is_open()){
		file << "\033[32m" << "         *          \n";
		file << "        ***         \n";
		file << "       *****        \n";
		file << "      *******       \n";
		file << "     *********      \n";
		file << "    ***********     \n";
		file << "   *************    \n";
		file << "  ***************   \n";
		file << " *****************  \n";
		file << "******************* \n";
		file << "       |||          \n";
		file << "       |||          ";
	}
	file.close();
}
