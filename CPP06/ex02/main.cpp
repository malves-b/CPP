#include "Base.hpp"
#include <ctime>

int main() {
	std::srand(std::time(NULL));
    Base *ptr = generate();

    std::cout << "Using pointer:" << std::endl;
    identify(ptr);

    std::cout << "Using reference:" << std::endl;
    identify(*ptr);

	// identify(NULL);

    delete ptr;
    return 0;
}
