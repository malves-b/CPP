#include "Span.hpp"
#include <ctime>
#include <cstdlib>

int main() {
    // try {
    //     Span sp(10000);

    //     std::srand(std::time(NULL));
    //     for (int i = 0; i < 10000; ++i)
    //         sp.addNumber(std::rand());

    //     std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
    //     std::cout << "Longest span: " << sp.longestSpan() << std::endl;

    // } catch (const std::exception& e) {
    //     std::cerr << "Error: " << e.what() << std::endl;
    // }


	/* ----- Subject Main ----- */
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

    return 0;
}
