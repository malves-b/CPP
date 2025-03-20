#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <chrono>
#include <iomanip>

int Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

int Account::getNbAccounts( void )		{return (_nbAccounts);}
int	Account::getTotalAmount( void )		{return (_totalAmount);}
int	Account::getNbDeposits( void )		{return (_totalNbDeposits);}
int	Account::getNbWithdrawals( void )	{return (_totalNbWithdrawals);}

Account::Account(int initial_deposit = 0)
{
	_displayTimestamp();
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
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount;
	if (_amount < withdrawal)
	{
		std::cout << "refused";
		return (false);
	}
	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	return (false);
}

void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts
	<< ";total:" << _totalAmount
	<< ";deposits:" << _totalNbDeposits
	<< ";withdrawals:" << _totalNbWithdrawals;
}

void	Account::displayStatus( void ) const 
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
	<< ";amount:" << _amount
	<< ";deposits:" << _nbDeposits
	<< ";withdrawals:" << _nbWithdrawals;
}

void Account::_displayTimestamp(void)
{
	//get the current time
	auto now = std::chrono::system_clock::now();
	std::time_t currentTime = std::chrono::system_clock::to_time_t(now);

	//Convert to local time and format the output
	std::tm* localTime = std::localtime(&currentTime);

	//Display the timestamp in the format: YYYY/MM/DD_HH:MM:SS
	std::cout << "["
              << (1900 + localTime->tm_year)  // Year
              << std::setw(2) << std::setfill('0') << (1 + localTime->tm_mon) //Month
              << std::setw(2) << std::setfill('0') << localTime->tm_mday  // Day
              << "_"
              << std::setw(2) << std::setfill('0') << localTime->tm_hour  // Hour
              << std::setw(2) << std::setfill('0') << localTime->tm_min   // Minute
              << std::setw(2) << std::setfill('0') << localTime->tm_sec   // Second
              << "]" << std::endl;
}
