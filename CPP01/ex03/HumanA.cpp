/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrizakov <mrizakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 15:13:37 by mrizakov          #+#    #+#             */
/*   Updated: 2024/02/10 14:59:01 by mrizakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "HumanA.hpp"
#include "Weapon.hpp"



// HumanA::HumanA(void) {
// }

HumanA::HumanA(std::string name, Weapon &weapon):_weapon(weapon) {
    this->_name = name;
}

HumanA::~HumanA(void) {
}

void HumanA::setName(std::string name) {
    this->_name = name;
}

void HumanA::attack(void) const {
    std::cout << this->_name << " attacks with their " << this->_weapon.getType() << std::endl;
}