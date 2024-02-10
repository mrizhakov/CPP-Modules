/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrizakov <mrizakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 15:13:37 by mrizakov          #+#    #+#             */
/*   Updated: 2024/02/10 19:08:18 by mrizakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Harl.hpp"


Harl::Harl(void) {
}

Harl::~Harl(void) {
}

void Harl::complain(std::string level) {
    (void)level;
    
}

void Harl::debug(void) {
    std::cout << "DEBUG" << std::endl;
}

void Harl::info(void) {
    std::cout << "INFO" << std::endl;
}

void Harl::warning(void) {
    std::cout << "WARNING" << std::endl;
}

void Harl::error(void) {
    std::cout << "ERROR" << std::endl;    
}