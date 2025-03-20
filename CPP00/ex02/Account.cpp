#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <chrono>

int Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

void Account::_displayTimestamp(void)
{
	//get the current time
	auto now = std::chrono::system_clock::now();
	std::time_t currentTime = std::chrono::system_clock::to_time_t(now);

	//
}

int Account::getNbAccounts(void)		{return (_nbAccounts);}
int	Account::getTotalAmount( void )		{return (_totalAmount);}
int	Account::getNbDeposits( void )		{return (_totalNbDeposits);}
int	Account::getNbWithdrawals( void )	{return (_totalNbWithdrawals);}

Account::Account(int initial_deposit = 0)
{
	_accountIndex = _nbAccounts;
	_amount = initial_deposit;
	initial_deposit == 0 ? _totalNbDeposits = 0 : _totalNbDeposits = 1;
	_nbAccounts++;
}

void	Account::makeDeposit(int deposit)
{
	_amount += deposit;
	_nbDeposits += 1;
	_totalAmount += deposit;
	_totalNbDeposits++;
}

int		Account::checkAmount( void ) const {return (_amount);}

bool	Account::makeWithdrawal( int withdrawal )
{
	if (_amount < withdrawal)
	{
		std::cout << "--- impossible operation ---\n";
		return (false);
	}
	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	return (false);
}

void	Account::displayAccountsInfos( void )
{
	std::cout << 
}

