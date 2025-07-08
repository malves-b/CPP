#include "RPN.hpp"

RPN::RPN(std::string str) : _input(str){}


RPN::RPN(const RPN &cpy){*this = cpy;}

RPN &RPN::operator=(const RPN other)
{
	if (this != &other)	{
		this->_stck = other._stck;
	}
	return *this;
}

RPN::~RPN(){}

int	RPN::execute()
{
	std::string::iterator it;
	std::string operators = "+-*/";

	for (it = _input.begin(); it != _input.end(); it++)
	{
		if (std::isdigit(*it)){
			_stck.push(*it - '0');
			continue;
		}
		if (std::isspace(*it))
			continue;
		size_t pos = operators.find(*it);
		if (pos == std::string::npos)
			throw std::runtime_error("Error: Invalid char");
		if (_stck.size() < 2)
			throw std::runtime_error("Error: Not enough operands");
		
		int b = _stck.top(); _stck.pop();
		int a = _stck.top(); _stck.pop();
		int result;

		switch (pos) {
			case 0: result = a + b; break;
			case 1: result = a - b; break;
			case 2: result = a * b; break;
			case 3:
				if (b == 0)
					throw std::runtime_error("Error: Division by zero");
				result = a / b;
				break;
			default:
				throw std::runtime_error("Error: Unknown operator");
		}
		_stck.push(result);
	}
	return _stck.top();
}