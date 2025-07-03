#include "BitcoinExchange.hpp"

/*
	'^' = search regex in start 
	'$' = search regex in end
	'*' = search 0 or more by the char
	'+' = search 1 or more by the char
	'.' = it could be anything
*/
bool	match_regex(const char* pattern, const std::string&text)
{
	regex_t	regex;

	if (regcomp(&regex, pattern, REG_EXTENDED) != 0)
		return std::cout << "Error compiling regex" << std::endl, 1;

	int result = regexec(&regex, text.c_str(), 0, NULL, 0);
	regfree(&regex);
	if (result == 0)
		return true;
	return false;	
}