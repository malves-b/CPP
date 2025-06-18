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
	Span(unsigned int N);
	Span(Span &cpy);
	~Span();

	Span &operator=(const Span &other);

	void addNumber(short nbr);

	int shortestSpan();
	int longestSpan();
};


#endif // SPAN_HPP
