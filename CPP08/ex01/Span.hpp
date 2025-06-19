#if !defined SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
#include <exception>

class Span
{
private:
	unsigned int _N;
	std::vector<int> v;
public:
	Span();
	Span(unsigned int N);
	Span(const Span &cpy);
	~Span();

	Span &operator=(const Span &other);

	void addNumber(int nbr);

	int shortestSpan() const;
	int longestSpan() const;

	template <typename Iterator>
	void addNumber(Iterator begin, Iterator end);
};

template <typename Iterator>
void Span::addNumber(Iterator begin, Iterator end)
{
	if (std::distance(begin, end) + v.size() > _N)
		throw std::runtime_error("Not enough space");
	v.insert(v.end(), begin, end);
}

#endif // SPAN_HPP