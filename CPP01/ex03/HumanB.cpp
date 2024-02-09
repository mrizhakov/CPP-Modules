/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrizakov <mrizakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 15:13:37 by mrizakov          #+#    #+#             */
/*   Updated: 2024/02/09 20:14:22 by mrizakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "HumanB.hpp"
#include "Weapon.hpp"



HumanB::HumanB(void) {
}

HumanB::HumanB(std::string name) {
    this->_name = name;
}

HumanB::~HumanB(void) {
}

void HumanB::setName(std::string name) {
    this->_name = name;
}

void HumanB::attack(void) const {
    std::cout << this->_name << " attacks with their " << this->_weapon.getType() << std::endl;
}

void HumanB::setWeapon(Weapon weapon) {
    this->_weapon.setType(weapon.getType());
}
