#include "AForm.hpp"
#include "Bureaucrat.hpp"

//Default constructor
AForm::AForm(): _name("default"), _signed(false), _signGrade(1), _exeGrade(1){}

//Parametized constructor
AForm::AForm(std::string name, const int signGrade, const int exeGrade): _name(name), _signed(false), _signGrade(signGrade), _exeGrade(exeGrade)
{
	if (this->_exeGrade < 1 || this->_signGrade < 1)
		throw GradeTooHighException();
	if (this->_exeGrade > 150 || this->_signGrade > 150)
		throw GradeTooLowException();
}

//Copy constructor
AForm::AForm(const AForm &cpy): _name(cpy._name), _signGrade(cpy._signGrade), _exeGrade(cpy._exeGrade){*this = cpy;}

//Destructor
AForm::~AForm(){std::cout << _name << " destroyed" << std::endl;}

//Operator overload
AForm &AForm::operator=(const AForm &other)
{
	if (this != &other)
		this->_signed = other._signed;
	return *this;
}

const char *AForm::GradeTooLowException::what() const throw(){return "Grade is too low";}

const char *AForm::GradeTooHighException::what() const throw(){return "Grade is too high";}

const char *AForm::FormNotSignedException::what() const throw(){return "Form not signed";}

std::string AForm::getName() const {return this->_name;}

bool AForm::getIsSigned() const {return (this->_signed == true) ? true : false;}

int AForm::getExeGrade() const {return this->_exeGrade;}

int AForm::getSignGrade() const {return this->_signGrade;}

void AForm::beSigned(Bureaucrat &executor)
{
	if (executor.getGrade() > this->getSignGrade()){
		throw GradeTooLowException();
	}
	this->_signed = true;
}

std::ostream &operator<<(std::ostream &os, AForm &obj)
{
	os << obj.getName() << "-> " <<
	"grade to execute: " << obj.getExeGrade() <<
	" | grade to sign: " << obj.getSignGrade() << std::endl;
	return os;
}
