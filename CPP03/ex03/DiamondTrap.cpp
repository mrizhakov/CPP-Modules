/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrizakov <mrizakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 19:01:04 by mrizakov          #+#    #+#             */
/*   Updated: 2024/02/23 14:18:38 by mrizakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

using std::cout;
using std::endl;
using std::string;

DiamondTrap::DiamondTrap(string name) : ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name) {
   this->_name =  name;
   this->_hp = FragTrap::_hp;
   this->_energy = ScavTrap::_energy;
   this->_damage = FragTrap::_damage;
   cout << "Diamondtrap " << this->_name << " is alive" << endl;
   cout << "Current stats are: HP: " << this->_hp << " Energy: " << this->_energy << endl;
}

DiamondTrap::~DiamondTrap(void) {
   cout << "Diamondtrap " << _name << " is unalive" << endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other)
{
   *this = other;
   cout << "Diamondtrap " << this->_name << " is alive by copy" << endl;
}

DiamondTrap&    DiamondTrap::operator=(const DiamondTrap& other)
{
   this->_name = other._name;
   this->_hp = other._hp;
   this->_energy = other._energy;
   cout << "Diamondtrap " << this->_name << " is alive by copy assignment" << endl;
   return *this;
}

void    DiamondTrap::whoAmI(void) {
   cout << "Diamondtrap's name is " << this->_name << endl;
   cout << "Diamondtrap ClapTrap name is  " << this->ClapTrap::_name << endl;
}