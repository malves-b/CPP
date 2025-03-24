#include "Contact.hpp"

std::string	set_variable(void){
    std::string input;
	if (!(std::cin >> input)) {
		if (std::cin.eof()) {
			std::cout << "\n--- Ctrl + D detected. Exiting program. ---\n";
			exit(1);
		}
	}
	return (input);
}

void	Contact::add_contact()
{
	std::cout << "First name: ";
	first_name = set_variable();
	std::cout << "Last name: ";
	last_name = set_variable();
	std::cout << "Nickname: ";
	nickname = set_variable();
	while (true) {
        std::cout << "Phone number (int): ";
        std::cin >> phone_number;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input! Please enter a valid integer for the phone number." << std::endl;
        }
		else {break;}
    }
	std::cout << "Darkest secret: ";
	darkest_secret = set_variable();

	if (first_name.empty() || last_name.empty() || nickname.empty() || darkest_secret.empty()) {
        std::cout << "All fields must be filled!" << std::endl;
        add_contact();
    }
}

std::string truncate_and_add_dot(const std::string& str)
{
	if (str.size() > 10) {
		return str.substr(0, 9) + ".";
	}
	return str;
}

void Contact::print_contacts() {
   
    std::cout << std::left;
    std::cout << std::setw(10) << truncate_and_add_dot(first_name) << "|";
    std::cout << std::setw(10) << truncate_and_add_dot(last_name) << "|";
    std::cout << std::setw(10) << truncate_and_add_dot(nickname) << "|" << std::endl;
}

void Contact::print_contact_details() {
    std::cout << "\nFirst name: " << first_name << std::endl;
    std::cout << "Last name: " << last_name << std::endl;
    std::cout << "Nickname: " << nickname << std::endl;
    std::cout << "Phone number: " << phone_number << std::endl;
    std::cout << "Darkest secret: " << darkest_secret << std::endl;
}