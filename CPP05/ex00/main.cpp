#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat	amauri;
	Bureaucrat	jao;

	// ----- test1 -----
	try{
		jao = Bureaucrat("Alirio", 151);}
	catch(const std::exception& e){
		std::cerr << e.what() << '\n';
	}

	// ----- test2 -----
	try{
		amauri = Bureaucrat("Amauri", 10);}
	catch(const std::exception& e){
		std::cerr << e.what() << '\n';
	}

	// ----- test3 -----
	// try{
	// 	jao = Bureaucrat("jao", 15);}
	// catch(const std::exception& e){
	// 	std::cerr << e.what() << '\n';
	// }

	// ----- test4 -----
	for (size_t i = 0; i < 12; i++)
	{
		try {
			amauri.increment();
			std::cout << amauri;
		}
		catch (const std::exception& e){
			std::cerr << e.what() << '\n';
		}
	}
	return 0;
}
