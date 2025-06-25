#include "BitcoinExchange.hpp"

int main(int argc, char const *argv[])
{
	if (argc != 2)
		return std::cout << "Error: could not open file." << std::endl, 1;
	std::cout << argv[1] << std::endl;
	return 0;
}

