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
		return (std::cout << "Error: impossible open the file" << std::endl), true;

	std::stringstream buffer;
	buffer << file.rdbuf();

	std::string line;
	while (std::getline(buffer, line)) {
        if (match_regex("^[0-9]{4}-[0-9]{2}-[0-9]{2} \\| [0-9]+(\\.[0-9]+)?$", line)) {
            size_t sep = line.find(" | ");
            std::string date = line.substr(0, sep);
            std::string val = line.substr(sep + 3);

            double value = std::atof(val.c_str());

            if (value > 2147483647.0) {
                std::cout << "Error: too large a number." << std::endl;
            } else {
                std::cout << date << " => " << val << " = X" << std::endl; // substitua X pela lógica do cálculo
            }
        }
        else if (match_regex("^[0-9]{4}-[0-9]{2}-[0-9]{2} \\| -[0-9]+(\\.[0-9]+)?$", line)) {
            std::cout << "Error: not a positive number." << std::endl;
        }
        else {
            std::cout << "Error: bad input => " << line << std::endl;
        }
    }

	return false;
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

