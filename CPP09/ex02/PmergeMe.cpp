#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void){}

PmergeMe::PmergeMe(std::vector<std::string> args){initVector(args);}

PmergeMe::~PmergeMe(){}

void PmergeMe::sortVector(std::vector<int> nbrs)
{
	if (nbrs.size() == 1)
	{
		this->_vectorAfter = nbrs;
		return;
	}

	std::vector<int> biggers;
	std::vector<int> smallers;

	// Guardar elemento extra se ímpar
	int rest = -1;
	if (nbrs.size() % 2 != 0)
	{
		rest = nbrs.back();
		nbrs.pop_back();
	}

	// Separar em pares (smallers e biggers)
	for (std::vector<int>::iterator it = nbrs.begin(); it < nbrs.end(); it += 2)
	{
		if (*it < *(it + 1))
		{
			smallers.push_back(*it);
			biggers.push_back(*(it + 1));
		}
		else
		{
			smallers.push_back(*(it + 1));
			biggers.push_back(*it);
		}
	}

	// Recursivamente ordenar os biggers
	PmergeMe aux;
	aux.sortVector(biggers);
	std::vector<int> mainChain = aux._vectorAfter;

	// ⚠️ Ainda não inserimos os smallers nem o rest — isso vem depois

	this->_vectorAfter = mainChain;

	printContainer(_vectorAfter);
}

void	PmergeMe::execute()
{
	this->sortVector(this->_vectorBefore);
}

void	PmergeMe::initVector(std::vector<std::string> args)
{
	for (size_t i = 0; i < args.size(); i++)
	{
		_vectorBefore.insert(_vectorBefore.end(), ::atoi(args.at(i).c_str()));
	}
	std::vector<int>::iterator it;
	
	std::cout << "Vector Before: ";
	for (it = _vectorBefore.begin(); it < _vectorBefore.end(); it++)
	{
		std::cout << *it << ' ';
	}
	std::cout << std::endl;
}







// 5 9 1 4 2

// (5 , 9) (1 , 4)        *2*

// biggers		smallers
// 9			5
// 4			1