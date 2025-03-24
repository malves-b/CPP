#include <string>
#include <iostream>
#include <iomanip>
#include <vector>
#include <cstdlib>
#include <limits>

#pragma once

class Contact
{
	private:
		std::string	first_name;
		std::string	last_name;
		std::string	nickname;
		int			phone_number;
		std::string	darkest_secret;
	public:
		void	add_contact();
		void	print_contacts();
		void	print_contact_details();
};
