#pragma once
#include "Contact.hpp"
#include <cstdlib>

using namespace std;

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
