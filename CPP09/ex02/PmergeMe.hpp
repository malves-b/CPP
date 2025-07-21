#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <ctime>
#include <cstdlib>
#include <climits>

class PmergeMe {
private:
    std::vector<int> _vectorBefore;
    std::vector<int> _vectorAfter;
    std::deque<int> _dequeBefore;
    std::deque<int> _dequeAfter;

    PmergeMe();

    size_t binarySearchVector(const std::vector<int>& vec, int value);
    size_t binarySearchDeque(const std::deque<int>& deq, int value);
    std::vector<int> sortVector(std::vector<int> nbrs);
    std::deque<int> sortDeque(std::deque<int> nbrs);
    void initContainers(std::vector<std::string> args);

public:
    PmergeMe(std::vector<std::string> args);
    PmergeMe(const PmergeMe& cpy);
    PmergeMe& operator=(const PmergeMe& other);
    ~PmergeMe();

    void execute();
};

template <typename T>
void printContainer(const T& container) {
    typename T::const_iterator it;
    for (it = container.begin(); it != container.end(); ++it) {
        std::cout << *it << ' ';
    }
    std::cout << std::endl;
}

#endif