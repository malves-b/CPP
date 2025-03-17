#include "PhoneBook.hpp"

int main(void)
{
	PhoneBook	newList;
	string		input;

	while (1)
	{
		cout << "\nEnter a command (ADD, SEARCH, EXIT): ";
		cin >> input;

		if (input == "ADD")
			newList.ADD();
		else if (input == "SEARCH")
			newList.SEARCH();
		else if (input == "EXIT")
			newList.EXIT();
		else
			cout << "Invalid command! ";
	}	
	return 0;
}
