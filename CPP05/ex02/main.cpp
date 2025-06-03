#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

void	shrubberyCreationTest(int executorGrade);
void	RobotomyRequestTest(int executorGrade);
void	presidentialPardonTest(int executorGrade);

int main()
{
	int	executorGrade;

	std::cout << "Give the bureaucrat a grade: ";
	std::cin >> executorGrade;
	std::cout << std::endl;

	std::cout << "------ ShrubberyCreationForm TEST ------\n\n";
	shrubberyCreationTest(executorGrade);
	std::cout << "\n------ PresidentialPardonForm TEST ------\n\n";
	presidentialPardonTest(executorGrade);
	std::cout << "\n------ RobotomyRequestForm TEST ------\n\n";
	RobotomyRequestTest(executorGrade);
	std::cout << "\n--------------------------------------";
	return 0;
}

void presidentialPardonTest(int executorGrade)
{
	PresidentialPardonForm P1("test");
	Bureaucrat executor("test", executorGrade);
	
	try {
		executor.signForm(P1);
	}
	catch (const std::exception& e){
		std::cout << e.what();
	}
	try
	{
		P1.execute(executor);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	executor.executeForm(P1);
}

void shrubberyCreationTest(int executorGrade)
{
	ShrubberyCreationForm S1("test");
	Bureaucrat executor("test", executorGrade);
	
	try {
		executor.signForm(S1);
	}
	catch (const std::exception& e){
		std::cout << e.what();
	}
	
	try
	{
		S1.execute(executor);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}	
}

void RobotomyRequestTest(int executorGrade)
{
	RobotomyRequestForm R1("test");
	Bureaucrat executor("test", executorGrade);
	
	try {
		executor.signForm(R1);
	}
	catch (const std::exception& e){
		std::cout << e.what();
	}
	try
	{
		R1.execute(executor);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}	
}
