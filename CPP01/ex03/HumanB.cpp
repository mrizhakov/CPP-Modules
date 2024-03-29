/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrizakov <mrizakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 15:13:37 by mrizakov          #+#    #+#             */
/*   Updated: 2024/02/10 15:04:50 by mrizakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "HumanB.hpp"
#include "Weapon.hpp"



HumanB::HumanB(std::string name) {
    this->_name = name;
    this->_weapon = NULL;
}

HumanB::~HumanB(void) {
}

void HumanB::setName(std::string name) {
    this->_name = name;
}

void HumanB::attack(void) const {
    if (!(this->_weapon))
        std::cout << this->_name << " attacks with their bare hands" << std::endl;
    else
        std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon &weapon) {
    this->_weapon = &weapon;
}
