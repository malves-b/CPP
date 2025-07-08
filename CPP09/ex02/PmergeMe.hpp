#if !defined PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <string>
#include <algorithm>
#include <ctime>

#include <vector>
#include <deque>

class PmergeMe
{
private:
	std::vector <int> _vectorBefore;
	std::vector <int> _vectorAfter;
	std::deque <int> _dequeBefore;
	std::deque <int> _dequeAfter;
public:
	PmergeMe(char const* argv);
	PmergeMe(PmergeMe& cpy);
	PmergeMe& operator=(PmergeMe &other);
	~PmergeMe();
};



#endif // PMERGEME_HPP
