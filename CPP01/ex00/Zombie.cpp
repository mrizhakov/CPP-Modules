/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrizakov <mrizakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 15:13:37 by mrizakov          #+#    #+#             */
/*   Updated: 2024/02/05 20:11:30 by mrizakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Zombie.hpp"


Zombie::Zombie(void) {
    this->_zombie_name = "anon Zombie";
    std::cout << this->_zombie_name << "is alive..." << std::endl;
}

Zombie::Zombie(std::string str) {
    this->_zombie_name = str;
    std::cout << this->_zombie_name << "is alive..." << std::endl;
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

