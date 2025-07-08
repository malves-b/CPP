#include "RPN.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
		return std::cout << "Invalid amount of argument" << std::endl, 1;
	
	try
	{
		RPN rpn(argv[1]);
		std::cout << rpn.execute() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}	
	return 0;
}
