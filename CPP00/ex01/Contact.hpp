#include <string>
#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

#pragma once

class Contact
{
	private:
		string	first_name;
		string	last_name;
		string	nickname;
		string	phone_number;
		string	darkest_secret;
	public:
		void	add_contact();
		void	print_contacts();
		void	print_contact_details();
};
