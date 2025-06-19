#include "Span.hpp"

Span::Span() : _N(0) {}

Span::Span(unsigned int N) : _N(N) {}

Span::Span(const Span &cpy){*this = cpy;}

Span::~Span(){}

Span &Span::operator=(const Span &other)
{
	if (this != &other)
	{
		this->_N = other._N;
		this->v.clear();
		this->v.insert(this->v.end(), other.v.begin(), other.v.end());
	}
	return *this;
}

void Span::addNumber(int nbr)
{
	if (this->v.size() < this->_N)
		return v.push_back(nbr);
	throw std::runtime_error("\u26D4 The container is full! \u26D4");
}

int Span::shortestSpan() const
{
	if (v.size() < 2)
		throw std::runtime_error("Not enough numbers to find a span");

	int shortest = std::numeric_limits<int>::max();
	
	std::vector<int> sorted = this->v;
	std::sort(sorted.begin(), sorted.end());

	for (size_t i = 0; i < sorted.size() - 1; i++)
	{
		int diff = std::abs(sorted[i + 1] - sorted[i]);
		if (diff < shortest)
			shortest = diff;
	}
	return shortest;
}

int Span::longestSpan() const
{
	if (v.size() < 2)
		throw std::runtime_error("Not enough numbers to find a span");
	int min = *std::min_element(v.begin(), v.end());
	int max = *std::max_element(v.begin(), v.end());
	return max - min;
}
