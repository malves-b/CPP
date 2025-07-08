#include "PmergeMe.hpp"

int main(int argc, char const *argv[])
{
	for (int i = 1; i < argc; i++)
	{
		if (::atoi(argv[i]) < 0)
			return std::cout << "Negative number found! " << std::endl, 1;
		if (::atol(argv[i]) > 2147483647)
			return std::cout << "Max integer overpast! " << std::endl, 1;
	}
	try
	{
		PmergeMe(argv);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	return 0;
}
