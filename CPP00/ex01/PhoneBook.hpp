#pragma once
#include "Contact.hpp"
#include <cstdlib>
#include <limits>

class PhoneBook{
	private:
		Contact	contacts[8];
		int		oldest;
		void	update_oldest();
	public:
		PhoneBook();
		void	ADD();
		void	SEARCH();
		void	EXIT();
};
