/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrizakov <mrizakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 15:13:37 by mrizakov          #+#    #+#             */
/*   Updated: 2024/02/12 15:45:30 by mrizakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Harl.hpp"


Harl::Harl(void) {
    log[0].level = "DEBUG";
    log[0].function = &Harl::debug;
    log[1].level = "INFO";
    log[1].function = &Harl::info;
    log[2].level = "WARNING";
    log[2].function = &Harl::warning;
    log[3].level = "ERROR";
    log[3].function = &Harl::error;
}

Harl::~Harl(void) {
}

void Harl::complain(std::string level) {
    int i = -1;
    while (i != 4) 
    {
        if (log[i].level == level)
            (this->*(log[i].function))();
        i++;
    }
    i = -1;
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