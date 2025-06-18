#include "Span.hpp"

Span::Span(unsigned int N) : _N(N) {}

Span::Span(Span &cpy){*this = cpy;}

Span::~Span(){}

Span &Span::operator=(const Span &other)
{
	if (this != &other)
	{
		this->_N = other._N;
		this->v = other.v;
	}
	return *this;
}

void Span::addNumber(short nbr)
{
	if (this->v.size() < this->_N)
		return v.push_back(nbr);
	throw std::runtime_error("U+26D4 The container is full! U+26D4");
}

int Span::shortestSpan()
{
	int shortest = std::numeric_limits<int>::max();
	
	std::vector<int> sorted = this->v;
	std::sort(sorted.begin(), sorted.end());

	if (v.size() < 2)
		throw std::runtime_error("Not enaught numbers to find a span");
	for (size_t i = 0; i < sorted.size() - 1; i++)
	{
		int diff = std::abs(sorted[i + 1] - sorted[i]);
		if (diff < shortest)
			shortest = diff;
	}
	return shortest;
}

int Span::longestSpan()
{
	if (v.size() < 2)
		throw std::runtime_error("Not enaught numbers to find a span");
	int min = *std::min_element(v.begin(), v.end());
	int max = *std::max_element(v.begin(), v.end());
	return max - min;
}
