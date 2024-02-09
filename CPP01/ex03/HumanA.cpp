/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrizakov <mrizakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 15:13:37 by mrizakov          #+#    #+#             */
/*   Updated: 2024/02/09 20:14:47 by mrizakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "HumanA.hpp"
#include "Weapon.hpp"



HumanA::HumanA(void) {
}

HumanA::HumanA(std::string name, Weapon weapon) {
    this->_name = name;
    this->_weapon.setType(weapon.getType());
}

HumanA::~HumanA(void) {
}

void HumanA::set_name(std::string name) {
    this->_name = name;
}

void HumanA::attack(void) const {
    std::cout << this->_name << " attacks with their " << this->_weapon.getType() << std::endl;
}