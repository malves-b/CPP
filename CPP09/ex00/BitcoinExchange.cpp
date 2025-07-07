#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(BitcoinExchange &cpy){*this =cpy;}

BitcoinExchange::~BitcoinExchange(){}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other) {
		this->prices = other.prices;
	}
	return *this;
}

void BitcoinExchange::loadPrices(const std::string& filename)
{
    std::ifstream file(filename.c_str());
    if (!file) {
        std::cerr << "Error: could not open data file." << std::endl;
        exit(1);
    }

    std::string line;
    std::getline(file, line);

    while (std::getline(file, line)) {
        size_t sep = line.find(',');
        if (sep == std::string::npos)
            continue;

        std::string date = line.substr(0, sep);
        double price = std::atof(line.substr(sep + 1).c_str());
        prices[date] = price;
    }
}

double BitcoinExchange::getClosestPrice(const std::string& date) const
{
    std::map<std::string, double>::const_iterator it = prices.lower_bound(date);
    if (it != prices.end() && it->first == date)
        return it->second;
    if (it == prices.begin())
        return 0.0;
    --it;
    return it->second;
}

bool BitcoinExchange::isValidDate(const std::string& date)
{
    if (date.size() != 10 || date[4] != '-' || date[7] != '-')
        return false;

    int year, month, day;
    char sep1, sep2;
    std::istringstream iss(date);
    if (!(iss >> year >> sep1 >> month >> sep2 >> day))
        return false;

    if (sep1 != '-' || sep2 != '-' || month < 1 || month > 12 || day < 1 || day > 31)
        return false;

    return true;
}

//Check if the str can be convert correctly to double
bool BitcoinExchange::isValidValue(const std::string& valueStr, double& value)
{
    std::istringstream iss(valueStr);
    if (!(iss >> value))
        return false;

    return true;
}

void BitcoinExchange::processInputFile(const std::string& filename) const
{
    std::ifstream file(filename.c_str());
    if (!file) {
        std::cerr << "Error: could not open file." << std::endl;
        return;
    }

    std::string line;
    std::getline(file, line);

    while (std::getline(file, line)) {
        size_t sep = line.find(" | ");
        if (sep == std::string::npos) {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }
        std::string date = line.substr(0, sep);
        std::string valueStr = line.substr(sep + 3);
        double value = 0.0;
        if (!isValidDate(date)) {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }
        if (!isValidValue(valueStr, value)) {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }
        if (value < 0) {
            std::cout << "Error: not a positive number." << std::endl;
        } else if (value > 1000) {
            std::cout << "Error: too large a number." << std::endl;
        } else {
            double price = getClosestPrice(date);
            std::cout << date << " => " << value << " = " << value * price << std::endl;
        }
    }
}
