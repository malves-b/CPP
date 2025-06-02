#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	ShrubberyCreationForm S1("test");
	Bureaucrat brc("test", 149);

	try {
		brc.signForm(S1);
	}
	catch (const std::exception& e){
		std::cout << e.what();
	}

	try
	{
		S1.execute(brc);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}	
	return 0;
}
