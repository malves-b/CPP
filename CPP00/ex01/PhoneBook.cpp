#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : oldest(0){}

void PhoneBook::update_oldest(){
	oldest = (oldest < 7) ? (oldest += 1) : 0;
}

void	PhoneBook::ADD(){
	cout << "\n--- Adding a new contact ---\n" << endl;
	contacts[oldest].add_contact();
	update_oldest();
}

void	PhoneBook::SEARCH(){
    std::cout << "--------------------------------|" << std::endl;
	std::cout << "Index     |First Name|Last Name |" << std::endl;
    std::cout << "--------------------------------|" << std::endl;
	for (short i = 0; i < 8; i++){
		contacts[i].print_contacts();
	}
    std::cout << "--------------------------------|" << std::endl;
	int index;
	cout << "Enter the index of the contact to display details: ";
	cin >> index;
	if (index >= 0 && index < 8)
		contacts[index].print_contact_details();
	else
		cout << "Invalid index!" << endl;
}

void PhoneBook::EXIT() {
    std::cout << "Exiting the phonebook..." << std::endl;
	exit(0);
}