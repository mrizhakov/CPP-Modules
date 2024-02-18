/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrizakov <mrizakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 15:13:37 by mrizakov          #+#    #+#             */
/*   Updated: 2024/02/12 16:24:33 by mrizakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Zombie.hpp"


Zombie::Zombie(void) {
    this->_zombie_name = "anon Zombie";
}

Zombie::Zombie(std::string str) {
    this->_zombie_name = str;
}

Zombie::~Zombie(void) {
    std::cout << this->_zombie_name << " died" << std::endl;
}

void Zombie::set_name(std::string name) {
    this->_zombie_name = name;
}

void Zombie::announce(void) {
    std::cout << this->_zombie_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

