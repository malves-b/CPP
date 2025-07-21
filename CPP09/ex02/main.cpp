#include "PmergeMe.hpp"
#include <cstdlib>
#include <cstring>
#include <stdexcept>

int main(int argc, char* argv[]) {
    if (argc < 2)
        return std::cout << "Invalid args" << std::endl, 1;

    std::vector<std::string> args;
    for (int i = 1; i < argc; i++) {
        char* end;
        long num = std::strtol(argv[i], &end, 10);
        if (*end != '\0' || num < 0 || num > INT_MAX) {
            std::cout << "Error" << std::endl;
            return 1;
        }
        args.push_back(argv[i]);
    }

    try {
        PmergeMe pm(args);
        pm.execute();
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
        return 1;
    }

    return 0;
}