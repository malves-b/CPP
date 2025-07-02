#include "BitcoinExchange.hpp"

bool	checkInput(std::string filename)
{
	if (filename.empty())
		return true;
	for (std::string::iterator it = filename.begin(); it != filename.end(); it++){
		if (::isalnum(*it)){
			return false;
		}
	}
	return true;
}

bool	openFile(std::string filename)
{
	std::ifstream file(filename.c_str());
	if (!file)
		return (std::cout << "Error: impossible open the file"), true;

	std::stringstream buffer;
	buffer << file.rdbuf();

	std::string line;
	while (std::getline(buffer, line)) {
		std::cout << "Linha: " << line << std::endl;
	}
}

int main(int argc, char const *argv[])
{
	if (argc != 2)
		return std::cout << "Error: could not open file." << std::endl, 1;
	if (checkInput(argv[1]))
		return std::cout << "Error: Invalid input" << std::endl, 1;

	if (openFile(argv[1]))
		return 1;
	



	return 0;
}

