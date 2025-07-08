#include "PmergeMe.hpp"

PmergeMe::PmergeMe(std::vector<std::string> args)
{
	for (size_t i = 1; i < input.size(); i++)
	{
		int value = ::atoi(input[i].c_str());
		_vectorBefore.insert(::atoi(input))
	}
}

PmergeMe::~PmergeMe(){}




// 5 9 1 4 2

// (5 , 9) (1 , 4)        *2*

// biggers		smallers
// 9			5
// 4			1