/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrizakov <mrizakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 19:01:04 by mrizakov          #+#    #+#             */
/*   Updated: 2024/02/23 14:16:47 by mrizakov         ###   ########.fr       */
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
   (void)other;
   cout << "Scavtrap " << this->_name << " is alive" << endl;
   return *this;
}

void ScavTrap::attack(const string& target) {
   if (this->_hp != 0 || this->_energy != 0)
   {
      this->_energy--;
      cout << this->_name << " attacked " << target << " and did " << this->_damage << endl;
   }
   else
      cout << "Scavtrap " << this->_name << " can't attack because it's energy or hp ar low" << endl;
}

void ScavTrap::takeDamage(unsigned int amount) {
   this->_damage -= amount;
   cout << "Scavtrap " << this->_name << " took " << amount << " points of damage" << endl;

}

void ScavTrap::beRepaired(unsigned int amount) {
   if (this->_hp != 0 || this->_energy != 0)
   {
      this->_energy--;
      this->_hp += amount;
      if (this->_hp > 10)
         this->_hp = 10;
      cout << "Scavtrap " << this->_name << " repaired itself"<< endl;
   }
   else
      cout << "Scavtrap " << this->_name << " can't attack because it's energy or hp ar low" << endl;
}

void  ScavTrap::guardGate(void) {
   cout << "Scavtrap " << this->_name << " is in guard mode" << endl;
}
   
   
