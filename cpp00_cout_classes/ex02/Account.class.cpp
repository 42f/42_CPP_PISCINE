#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include "Account.class.hpp"
#include <time.h>
#include <ctime>

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Account::Account( int initial_deposit )
{
	this->_accountIndex = Account::_nbAccounts;
	this->_amount = 0;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	Account::_displayTimestamp();
	if (initial_deposit >= 0)
		this->_amount = initial_deposit;
	else
		std::cerr << "Cannot accept this initial deposit" << std::endl;
	Account::_totalAmount += initial_deposit;
	std::cout	<< "index:" << this->_accountIndex
				<< ";amount:" << this->_amount
				<< ";created"
				<< std::endl;
	Account::_nbAccounts++;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Account::~Account()
{
	Account::_displayTimestamp();
	std::cout	<< "index:" << this->_accountIndex
				<< ";amount:" << this->_amount
				<< ";closed"
				<< std::endl;
	Account::_nbAccounts--;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

/*
** --------------------------------- METHODS ----------------------------------
*/


/*
** --------------------------------- ACCESSOR ---------------------------------
*/

int		Account::getNbAccounts( void ) {
	return (Account::_nbAccounts);
}

int		Account::getTotalAmount( void ) {
	return (Account::_totalAmount);

}

int		Account::getNbDeposits( void ) {
	return (Account::_totalNbDeposits);
}

int		Account::getNbWithdrawals( void ) {
	return (Account::_totalNbWithdrawals);
}

void	Account::displayAccountsInfos( void ) {
	Account::_displayTimestamp();
	std::cout	<< "accounts:" << Account::getNbAccounts()
				<< ";total:" << Account::getTotalAmount()
				<< ";deposits:" << Account::getNbDeposits()
				<< ";withdrawals:" << Account::getNbWithdrawals()
				<< std::endl;
}

void	Account::makeDeposit( int deposit ) {
	Account::_displayTimestamp();
	std::cout	<< "index:" << this->_accountIndex
				<< ";p_amount:" << this->_amount
				<< ";deposit:" << deposit;
	this->_amount += deposit;
	this->_nbDeposits++;
	Account::_totalAmount += deposit;
	Account::_totalNbDeposits++;
	std::cout	<< ";amount:" << this->_amount
				<< ";nb_deposits:" << this->_nbDeposits
				<< std::endl;
}

bool	Account::makeWithdrawal( int withdrawal ) {
	Account::_displayTimestamp();
	std::cout	<< "index:" << this->_accountIndex
				<< ";p_amount:" << this->_amount
				<< ";withdrawal:";
	if (Account::checkAmount() - withdrawal >= 0)
	{
		this->_amount -= withdrawal;
		this->_nbWithdrawals++;
		Account::_totalAmount -= withdrawal;
		Account::_totalNbWithdrawals++;
		std::cout 	<< withdrawal
					<< ";amount:" << this->_amount
					<< ";nb_withdrawals:" << this->_nbWithdrawals
					<< std::endl;
		return (true);
	}
	else
	{
		std::cout << "refused" << std::endl;
		return (false);
	}
}

int		Account::checkAmount( void ) const {
	return (this->_amount);
}

void	Account::displayStatus( void ) const {
	Account::_displayTimestamp();
	std::cout	<< "index:" << this->_accountIndex
				<< ";amount:" << this->_amount
				<< ";deposits:" << this->_nbDeposits
				<< ";withdrawals:" << this->_nbWithdrawals
				<< std::endl;
}

void	Account::_displayTimestamp( void ){
	time_t theTime = time(NULL);
	struct tm *aTime = localtime(&theTime);

 	std::cout << '[' << aTime->tm_year + 1900; // Year is # years since 1900
	std::cout << std::setw(2) << std::setfill('0') << aTime->tm_mon + 1; // Month is 0 - 11, add 1 to get a jan-dec 1-12 concept
	std::cout << std::setw(2) << std::setfill('0') << aTime->tm_mday;
	std::cout << '_';
	std::cout << std::setw(2) << std::setfill('0') << aTime->tm_hour;
	std::cout << std::setw(2) << std::setfill('0') << aTime->tm_min;
	std::cout << std::setw(2) << std::setfill('0') << aTime->tm_sec;
	std::cout << "] ";
}

int		Account::_nbAccounts = 0;
int		Account::_totalAmount = 0;
int		Account::_totalNbDeposits = 0;
int		Account::_totalNbWithdrawals = 0;

/* ************************************************************************** */
