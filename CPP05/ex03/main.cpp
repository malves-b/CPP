#include "Intern.hpp"

void	subjectTest();
void	wrongTest();
void	shrubberyTest();
void	robotomyTest();
void	presidentialTest();

int main()
{
	subjectTest();
	wrongTest();
	shrubberyTest();
	robotomyTest();
	presidentialTest();
	std::cout << yellow <<"\n--------------------------------" << reset << std::endl;
	return 0;
}

void subjectTest()
{
	Intern someRandomIntern;
	AForm* rrf;

	std::cout << yellow <<"\n----- Subject test -----\n" << reset;
	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	delete rrf;
}

void wrongTest()
{
	Intern intern = Intern();
	AForm *errorTest = NULL;

	std::cout << yellow <<"\n----- Wrong test -----\n" << reset;
	try {
		errorTest = intern.makeForm("error test", "T3");
	}
	catch(const std::exception& e){
		std::cerr << e.what() << '\n';
	}
	if (errorTest)
		std::cout << errorTest->getName();
}

void shrubberyTest()
{
	Intern	intern = Intern();
	AForm	*a1 = NULL;

	a1 = intern.makeForm("shrubbery creation", "T1");

	std::cout << yellow <<"\n----- Shrubbery created -----\n" << reset;
	std::cout << "Name: " << green << a1->getName() << reset << std::endl;
	std::cout << "Sign Grade: " << a1->getSignGrade() << std::endl;
	std::cout << "Exe Grade: " << a1->getExeGrade() << std::endl;
	delete a1;
}

void robotomyTest()
{
	Intern	intern = Intern();
	AForm	*a1 = NULL;

	a1 = intern.makeForm("robotomy request", "T1");

	std::cout << yellow <<"\n----- Robotomy created -----\n" << reset;
	std::cout << "Name: " << green << a1->getName() << reset << std::endl;
	std::cout << "Sign Grade: " << a1->getSignGrade() << std::endl;
	std::cout << "Exe Grade: " << a1->getExeGrade() << std::endl;
	delete a1;
}

void presidentialTest()
{
	Intern	intern = Intern();
	AForm	*a1 = NULL;

	a1 = intern.makeForm("presidential pardon", "T1");

	std::cout << yellow <<"\n----- Presidential created -----\n" << reset;
	std::cout << "Name: " << green << a1->getName() << reset << std::endl;
	std::cout << "Sign Grade: " << a1->getSignGrade() << std::endl;
	std::cout << "Exe Grade: " << a1->getExeGrade() << std::endl;
	delete a1;
}