/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrizhakov <mrizhakov@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 20:50:50 by mrizakov          #+#    #+#             */
/*   Updated: 2024/02/10 19:24:11 by mrizhakov        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <limits>
#include "Account.hpp"

int	Account::getNbAccounts( void ) {
    return _nbAccounts;
}

int	Account::getTotalAmount( void ) {
    return _totalAmount;
}
int	Account::getNbDeposits( void ) {
    return _totalNbDeposits;
}
int	Account::getNbWithdrawals( void ) {
    return _totalNbWithdrawals;
}
void	Account::displayAccountsInfos( void ) {
    // std::cout << "Account Index :" << this->_accountIndex << std::endl;
    
}

Account::Account( int initial_deposit ) {
    
}
Account::~Account( void ) {
    
}

void	Account::makeDeposit( int deposit ) {
    
    
}
bool	Account::makeWithdrawal( int withdrawal ) {
    bool i;
    
    return (i);
}
int		Account::checkAmount( void ) const {
    int i;
    
    return (i);
}
void	Account::displayStatus( void ) const {
    
}

