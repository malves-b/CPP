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

	PmergeMe(void);
	
	void	initVector(std::vector<std::string> args);

public:
	PmergeMe(std::vector<std::string> args);
	PmergeMe(PmergeMe& cpy);
	PmergeMe& operator=(PmergeMe &other);
	~PmergeMe();

	void	execute();

	void	sortVector(std::vector<int>nbrs);
	// void	PmergeMe::sortDeque();

};

template <typename T>
void	printContainer(T &container)
{
	typename T::const_iterator it;
	for (it = container.begin(); it != container.end(); it++)
	{
		std::cout << *it << ' ';
	}
	std::cout << std::endl;
}

#endif // PMERGEME_HPP
