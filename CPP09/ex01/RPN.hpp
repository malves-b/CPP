#if !defined RPN_HPP
#define RPN_HPP

#include <iostream>
#include <algorithm>
#include <stack>
#include <string_view>

class RPN
{
private:
	std::stack<int> _stck;
	std::string	_input;
public:
	RPN(std::string str);
	RPN(const RPN &cpy);
	RPN& operator=(const RPN other);
	~RPN();

	int	execute();
};

#endif
