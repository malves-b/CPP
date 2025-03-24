#include "PhoneBook.hpp"

int main(void)
{
    PhoneBook newList;
    std::string input;

    while (true) {
        std::cout << "\nEnter a command (ADD, SEARCH, EXIT): ";

        if (!(std::cin >> input)) {
            if (std::cin.eof())
				std::cout << "\n--- Ctrl + D detected. Exiting program. ---\n";
			exit(1);
        } else {
            if (input == "ADD")
                newList.ADD();
            else if (input == "SEARCH")
                newList.SEARCH();
            else if (input == "EXIT") {
                newList.EXIT();
                break;
            } else {
                std::cout << "Invalid command! ";
            }
        }
    }
    return 0;
}
