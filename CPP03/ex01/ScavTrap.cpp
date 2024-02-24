/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrizakov <mrizakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 19:01:04 by mrizakov          #+#    #+#             */
/*   Updated: 2024/02/24 18:03:34 by mrizakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

using std::cout;
using std::endl;
using std::string;

ScavTrap::ScavTrap(void) : ClapTrap(), _name("no name")  {
   this->_hp =  100;
   this->_energy =  50;
   this->_damage =  20;
   cout << "Scavtrap " << this->_name << " is alive" << endl;
}

ScavTrap::ScavTrap(string name) : ClapTrap(name) {
   this->_name =  name;
   this->_hp =  100;
   this->_energy =  50;
   this->_damage =  20;
   cout << "Scavtrap " << this->_name << " is alive" << endl;
}

ScavTrap::~ScavTrap(void) {
   cout << "Scavtrap " << _name << " is unalive" << endl;
}

ScavTrap::ScavTrap(const ScavTrap& other)
{
   *this = other;
   cout << "Scavtrap " << this->_name << " is alive" << endl;
}

ScavTrap&    ScavTrap::operator=(const ScavTrap& other)
{
   this->_name = other._name;
   this->_hp = other._hp;
   this->_energy = other._energy;
   cout << "Scavtrap " << this->_name << " is alive" << endl;
   return *this;
}

void  ScavTrap::guardGate(void) {
   cout << "Scavtrap " << this->_name << " is in guard mode" << endl;
}
   
   
