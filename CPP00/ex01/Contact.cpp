#include "Contact.hpp"

void	Contact::add_contact()
{
	cout << "First name: ";
	cin >> first_name;
	cout << "Last name: ";
	cin >> last_name;
	cout << "Nickname: ";
	cin >> nickname;
	cout << "Phone number: ";
	cin >> phone_number;
	cout << "Darkest secret: ";
	cin >> darkest_secret;

	if (first_name.empty() || last_name.empty() || nickname.empty() || phone_number.empty() || darkest_secret.empty()) {
        cout << "All fields must be filled!" << endl;
        add_contact();
    }
}


void	Contact::print_contacts()
{
	cout << left;
	cout << setw(10) << first_name.substr(0, 10) << "|";
	cout << setw(10) << last_name.substr(0, 10) << "|";
	cout << setw(10) << nickname.substr(0, 10) << "|" << endl;
}

void Contact::print_contact_details() {
    cout << "\nFirst name: " << first_name << endl;
    cout << "Last name: " << last_name << endl;
    cout << "Nickname: " << nickname << endl;
    cout << "Phone number: " << phone_number << endl;
    cout << "Darkest secret: " << darkest_secret << endl;
}