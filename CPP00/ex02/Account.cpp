#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>

int Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

int Account::getNbAccounts( void )		{return (_nbAccounts);}
int	Account::getTotalAmount( void )		{return (_totalAmount);}
int	Account::getNbDeposits( void )		{return (_totalNbDeposits);}
int	Account::getNbWithdrawals( void )	{return (_totalNbWithdrawals);}

Account::Account(int initial_deposit)
{
	_displayTimestamp();
	_accountIndex = _nbAccounts;
	_amount = initial_deposit;
	std::cout << "index:" << this->_accountIndex
	<< ";amount:" << this->_amount << ";created\n";
	_nbAccounts++;
	_totalAmount += initial_deposit;
}

Account::~Account()
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
	<< ";amount:" << this->_amount
	<< ";closed\n";
}

void	Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
	<< ";p_amount:" << this->_amount
	<< ";deposit:" << deposit;
	_amount += deposit;
	_totalNbDeposits++;
	std::cout << ";amount:" << this->_amount;
	this->_nbDeposits++;
	std::cout << ";nb_deposit:" << this->_nbDeposits << "\n";
	_totalAmount += deposit;
}

int		Account::checkAmount( void ) const {return (_amount);}

bool	Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount;
	if (_amount < withdrawal)
	{
		std::cout << "withdrawal:refused\n";
		return (false);
	}
	std::cout << "withdrawal:" << withdrawal;
	_amount -= withdrawal;
	std::cout << ";amount:" << this->_amount;
	_totalAmount -= withdrawal;
	_totalNbWithdrawals++;
	this->_nbWithdrawals++;
	std::cout << ";nb_withdrawals:" << this->_nbWithdrawals << "\n";
	return (false);
}

void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts()
	<< ";total:" << getTotalAmount()
	<< ";deposits:" << getNbDeposits()
	<< ";withdrawals:" << getNbWithdrawals() << "\n";
}

void	Account::displayStatus( void ) const 
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
	<< ";amount:" << this->_amount
	<< ";deposits:" << this->_nbDeposits
	<< ";withdrawals:" << this->_nbWithdrawals << "\n";
}

void Account::_displayTimestamp(void) {
	std::time_t timestamp = std::time(NULL);
	std::tm *tm = std::localtime(&timestamp);
	std::cout << "[" << tm->tm_year + 1900; 
	std::cout << std::setfill('0') << std::setw(2) << tm->tm_mon + 1;
	std::cout << std::setfill('0') << std::setw(2) << tm->tm_mday << "_";
	std::cout << std::setfill('0') << std::setw(2) << tm->tm_hour;
	std::cout << std::setfill('0') << std::setw(2) << tm->tm_min;
	std::cout << std::setfill('0') << std::setw(2) << tm->tm_sec << "] ";
}