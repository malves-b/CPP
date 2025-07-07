#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <cstdlib>

class BitcoinExchange {
	private:
    std::map<std::string, double> prices;

	public:
    BitcoinExchange();
    BitcoinExchange(BitcoinExchange &cpy);
    ~BitcoinExchange();
	BitcoinExchange& operator=(const BitcoinExchange &other);

	void loadPrices(const std::string& filename);
	double getClosestPrice(const std::string& date) const;
	void processInputFile(const std::string& filename) const;
	static bool isValidDate(const std::string& date);
	static bool isValidValue(const std::string& valueStr, double& value);
};

#endif
