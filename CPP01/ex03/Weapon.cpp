/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrizakov <mrizakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 15:13:37 by mrizakov          #+#    #+#             */
/*   Updated: 2024/02/10 15:03:24 by mrizakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Weapon.hpp"

Weapon::Weapon(void) {
    this->_type = "no weapon";
}

Weapon::Weapon(std::string type) {
    this->_type = type;
}

Weapon::~Weapon(void) {
}

std::string const Weapon::getType(void) const{
    std::string const &type_ref = this->_type;
    return type_ref;
}
void        Weapon::setType(std::string str) {
    this->_type = str;
    return;
}