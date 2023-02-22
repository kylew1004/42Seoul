/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klew <klew@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 19:24:13 by klew              #+#    #+#             */
/*   Updated: 2023/02/22 19:24:15 by klew             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <iomanip>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account( int initial_deposit ) {
	_accountIndex = _nbAccounts;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;

	_nbAccounts++;
	_totalAmount += initial_deposit;
	
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
	   << ";" << "amount:" << _amount
	   << ";" << "created" << std::endl;
}

Account::~Account( void ) {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
	   << ";" << "amount:" << _amount
	   << ";" << "closed" << std::endl;
}

int	Account::getNbAccounts( void ){
	return (_nbAccounts);
}

int	Account::getTotalAmount( void ){
	return (_totalAmount);
}

int	Account::getNbDeposits( void ) {
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals( void ) {
	return (_totalNbWithdrawals);
}

void	Account::displayAccountsInfos( void ) {
	_displayTimestamp();
	std::cout 	<< "accounts:" << _nbAccounts 
	     << ";" << "total:" << _totalAmount
		 << ";" << "deposits:" << _totalNbDeposits
		 << ";" << "withdrawals:" << _totalNbWithdrawals
		 << std::endl;
}

void	Account::makeDeposit( int deposit ) {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";deposit:" << deposit << ";";

	_amount += deposit;
	_nbDeposits++;

	_totalAmount += deposit;
	_totalNbDeposits++;

	std::cout << "amount:" << _amount << ";nb_deposits:" << _nbDeposits << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal ) {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";withdrawal:";

	if (withdrawal > _amount)
	{
		std::cout << "refused" << std::endl;
		return false;
	}
	else
	{
		_amount -= withdrawal;
		_nbWithdrawals++;

		_totalAmount -= withdrawal;
		_totalNbWithdrawals++;

		std::cout << withdrawal << ";amount:" << _amount << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
		return true;
	}
}

int		Account::checkAmount( void ) const {
	return 0;
}

void	Account::displayStatus( void ) const {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
	   << ";" << "amount:" << _amount
	   << ";" << "deposits:" << _nbDeposits
	   << ";" << "withdrawals:" << _nbWithdrawals
	   << std::endl;
}

void	Account::_displayTimestamp( void ) {
	std::time_t	timestamp = time(NULL);
	tm	*date = localtime(&timestamp);

	std::cout << "[";
	std::cout << 1900 + date->tm_year;
	std::cout << std::setw(2) << std::setfill('0') << date->tm_mon;
	std::cout << std::setw(2) << std::setfill('0') << date->tm_mday;
	std::cout << "_";
	std::cout << std::setw(2) << std::setfill('0') << date->tm_hour;
	std::cout << std::setw(2) << std::setfill('0') << date->tm_min;
	std::cout << std::setw(2) << std::setfill('0') << date->tm_sec;
	std::cout << "] ";
}
