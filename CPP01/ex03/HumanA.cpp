/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrizakov <mrizakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 15:13:37 by mrizakov          #+#    #+#             */
/*   Updated: 2024/02/07 20:52:24 by mrizakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "HumanA.hpp"
#include "Weapon.hpp"



HumanA::HumanA(void) {
    this->_zombie_name = "anon Zombie";
    std::cout << this->_zombie_name << "is alive..." << std::endl;
}

HumanA::HumanA(std::string name, Weapon weapon) {
    this->_name = name;
    We
    std::cout << this->_zombie_name << "is alive..." << std::endl;
}

HumanA::~HumanA(void) {
    std::cout << this->_zombie_name << " died" << std::endl;
}

void HumanA::set_name(std::string name) {
    this->_zombie_name = name;
}

void HumanA::announce(void) {
    std::cout << this->_zombie_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

