#include "Account.hpp"
#include <iostream>

int	Account::getNbAccounts( void )
{
	return (_nbAccounts);
}

int	Account::getTotalAmount( void )
{
	return (_totalAmount);
}

int	Account::getNbDeposits( void )
{
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals( void )
{
	return (_totalNbWithdrawals);
}

Account::Account(int initial_deposit)
{
	_amount = initial_deposit;
	_totalNbDeposits = 1;
}

Account::Account(void)
{
	_amount = 0;
	_nbDeposits = 0;
}

void	Account::makeDeposit(int deposit)
{
	_amount += deposit;
	_nbDeposits += 1;
}

int		Account::checkAmount( void ) const
{
	return (_amount);
}

bool	Account::makeWithdrawal( int withdrawal )
{
	if (_amount >= withdrawal)
	{
		_amount -= withdrawal;
		return (true);
	}
	else{
		std::cout << "--- impossible operation ---\n";
		return (false);
	}
}
