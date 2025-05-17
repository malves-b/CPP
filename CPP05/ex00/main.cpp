#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat x = Bureaucrat("carlo", 151); 
	Bureaucrat y = Bureaucrat("alirio", 0);
	Bureaucrat right = Bureaucrat("right", 10);

	for (size_t i = 0; i < 15; i++)
	{
		right.increment();
		std::cout << right.getGrade() << std::endl;
	}
	return 0;
}
