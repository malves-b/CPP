#include "Span.hpp"
#include <ctime>
#include <cstdlib>

int main() {
    try {
        Span sp(10000);

        std::srand(std::time(NULL));
        for (int i = 0; i < 10000; ++i)
            sp.addNumber(std::rand());

        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
