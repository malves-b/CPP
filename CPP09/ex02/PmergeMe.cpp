#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(std::vector<std::string> args) {
    initContainers(args);
}

PmergeMe::PmergeMe(const PmergeMe& cpy) {
    *this = cpy;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
    if (this != &other) {
        _vectorBefore = other._vectorBefore;
        _vectorAfter = other._vectorAfter;
        _dequeBefore = other._dequeBefore;
        _dequeAfter = other._dequeAfter;
    }
    return *this;
}

PmergeMe::~PmergeMe() {}

void PmergeMe::initContainers(std::vector<std::string> args) {
    for (size_t i = 0; i < args.size(); i++) {
        long num = std::strtol(args[i].c_str(), NULL, 10);
        if (num < 0 || num > INT_MAX) {
            throw std::runtime_error("Error");
        }
        _vectorBefore.push_back(static_cast<int>(num));
        _dequeBefore.push_back(static_cast<int>(num));
    }
}

size_t PmergeMe::binarySearchVector(const std::vector<int>& vec, int value) {
    size_t low = 0;
    size_t high = vec.size();
    while (low < high) {
        size_t mid = (low + high) / 2;
        if (vec[mid] < value)
            low = mid + 1;
        else
            high = mid;
    }
    return low;
}

size_t PmergeMe::binarySearchDeque(const std::deque<int>& deq, int value) {
    size_t low = 0;
    size_t high = deq.size();
    while (low < high) {
        size_t mid = (low + high) / 2;
        if (deq[mid] < value)
            low = mid + 1;
        else
            high = mid;
    }
    return low;
}

std::vector<int> PmergeMe::sortVector(std::vector<int> nbrs) {
    if (nbrs.size() <= 1)
        return nbrs;

    bool has_rest = false;
    int rest = 0;
    if (nbrs.size() % 2 != 0) {
        rest = nbrs.back();
        nbrs.pop_back();
        has_rest = true;
    }

    std::vector<std::pair<int, int> > currentPairs;
    for (size_t i = 0; i < nbrs.size(); i += 2) {
        if (nbrs[i] < nbrs[i + 1])
            currentPairs.push_back(std::make_pair(nbrs[i], nbrs[i + 1]));
        else
            currentPairs.push_back(std::make_pair(nbrs[i + 1], nbrs[i]));
    }

    std::vector<int> biggers;
    for (size_t i = 0; i < currentPairs.size(); i++)
        biggers.push_back(currentPairs[i].second);

    std::vector<int> sortedBiggers = sortVector(biggers);
    std::vector<int> mainChain = sortedBiggers;

    if (!sortedBiggers.empty()) {
        int firstSmaller = -1;
        for (size_t i = 0; i < currentPairs.size(); i++) {
            if (currentPairs[i].second == sortedBiggers[0]) {
                firstSmaller = currentPairs[i].first;
                break;
            }
        }
        if (firstSmaller != -1) {
            size_t pos = binarySearchVector(mainChain, firstSmaller);
            mainChain.insert(mainChain.begin() + pos, firstSmaller);
        }
    }

    for (size_t i = 1; i < sortedBiggers.size(); i++) {
        int smaller = -1;
        for (size_t j = 0; j < currentPairs.size(); j++) {
            if (currentPairs[j].second == sortedBiggers[i]) {
                smaller = currentPairs[j].first;
                break;
            }
        }
        if (smaller != -1) {
            size_t pos = binarySearchVector(mainChain, smaller);
            mainChain.insert(mainChain.begin() + pos, smaller);
        }
    }

    if (has_rest) {
        size_t pos = binarySearchVector(mainChain, rest);
        mainChain.insert(mainChain.begin() + pos, rest);
    }

    return mainChain;
}

std::deque<int> PmergeMe::sortDeque(std::deque<int> nbrs) {
    if (nbrs.size() <= 1)
        return nbrs;

    bool has_rest = false;
    int rest = 0;
    if (nbrs.size() % 2 != 0) {
        rest = nbrs.back();
        nbrs.pop_back();
        has_rest = true;
    }

    std::vector<std::pair<int, int> > currentPairs;
    for (size_t i = 0; i < nbrs.size(); i += 2) {
        if (nbrs[i] < nbrs[i + 1])
            currentPairs.push_back(std::make_pair(nbrs[i], nbrs[i + 1]));
        else
            currentPairs.push_back(std::make_pair(nbrs[i + 1], nbrs[i]));
    }

    std::deque<int> biggers;
    for (size_t i = 0; i < currentPairs.size(); i++)
        biggers.push_back(currentPairs[i].second);

    std::deque<int> sortedBiggers = sortDeque(biggers);
    std::deque<int> mainChain = sortedBiggers;

    if (!sortedBiggers.empty()) {
        int firstSmaller = -1;
        for (size_t i = 0; i < currentPairs.size(); i++) {
            if (currentPairs[i].second == sortedBiggers[0]) {
                firstSmaller = currentPairs[i].first;
                break;
            }
        }
        if (firstSmaller != -1) {
            size_t pos = binarySearchDeque(mainChain, firstSmaller);
            mainChain.insert(mainChain.begin() + pos, firstSmaller);
        }
    }

    for (size_t i = 1; i < sortedBiggers.size(); i++) {
        int smaller = -1;
        for (size_t j = 0; j < currentPairs.size(); j++) {
            if (currentPairs[j].second == sortedBiggers[i]) {
                smaller = currentPairs[j].first;
                break;
            }
        }
        if (smaller != -1) {
            size_t pos = binarySearchDeque(mainChain, smaller);
            mainChain.insert(mainChain.begin() + pos, smaller);
        }
    }

    if (has_rest) {
        size_t pos = binarySearchDeque(mainChain, rest);
        mainChain.insert(mainChain.begin() + pos, rest);
    }

    return mainChain;
}

void PmergeMe::execute() {
    std::cout << "Before: ";
    printContainer(_vectorBefore);

    clock_t start = clock();
    _vectorAfter = sortVector(_vectorBefore);
    clock_t end = clock();
    double vectorTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;

    start = clock();
    _dequeAfter = sortDeque(_dequeBefore);
    end = clock();
    double dequeTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;

    std::cout << "After: ";
    printContainer(_vectorAfter);

    std::cout << "Time to process a range of " << _vectorBefore.size() << " elements with std::vector : " << vectorTime << " us" << std::endl;
    std::cout << "Time to process a range of " << _dequeBefore.size() << " elements with std::deque : " << dequeTime << " us" << std::endl;
}

// 5 9 1 4 2

// (5 , 9) (1 , 4)        *2*

// biggers		smallers
// 9			5
// 4			1