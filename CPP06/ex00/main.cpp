#include "ScalarConverter.hpp"

int main(int argc, const char *argv[])
{
	if (argc != 2)
		return (std::cout << "Invalid numbers of arguments"), 1;
	return (ScalarConverter::convert(argv[1])), 0;
}
