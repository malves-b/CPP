#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include "easyfind.hpp"

void testVector(int nbr);
void testList(int nbr);
void testDeque(int nbr);

int main()
{
	std::cout << "Choose a container type: \n" <<
	"1 - vector\n" << "2 - List\n" << "3 - Deque" << std::endl;
	int i; std::cin >> i;

	std::cout << "Digit a number to search inside the container: (1 to 10): ";
	int nbr; std::cin >> nbr;
	
	switch (i)
	{
		case 1:
			testVector(nbr);
			break;
		case 2:
			testList(nbr);
			break;
		case 3:
			testDeque(nbr);
			break;
		default:
			std::cerr << "Invalid option. Use:\n1 - Vector\n2 - List\n3 - Deque\n";
			break;
	}
	return 0;
}

void testVector(int nbr) {
    std::vector<int> vec;

	vec.push_back(1);
	vec.push_back(4);
	vec.push_back(9);

	std::cout << "\nTesting std::vector:" << std::endl;

    try {
        easyfind(vec, nbr);
		std::cout << "found: " << nbr << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

void testList(int nbr) {
    std::list<int> lst;

	lst.push_back(1);
	lst.push_back(4);
	lst.push_back(9);

	std::cout << "\nTesting std::list:" << std::endl;

    try {
        easyfind(lst, nbr);
		std::cout << "found: " << nbr << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

void testDeque(int nbr) {
    std::deque<int> deq;

	deq.push_back(1);
	deq.push_back(4);
	deq.push_back(9);

    std::cout << "\nTesting std::deque:" << std::endl;

    try {
        easyfind(deq, 0);
		std::cout << "found: " << nbr << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}
