/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrizakov <mrizakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 19:01:04 by mrizakov          #+#    #+#             */
/*   Updated: 2024/02/23 17:42:54 by mrizakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

using std::cout;
using std::endl;
using std::string;

ScavTrap::ScavTrap(void) :_name("no name"), _hp(10), _energy(10), _damage(0)  {
   cout << "Scavtrap " << this->_name << " is alive" << endl;
}

ScavTrap::ScavTrap(string name) {
   this->_name =  name;
   this->_hp =  10;
   this->_energy =  10;
   this->_damage =  0;
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
https://www.fantasy.top/
void ScavTrap::takeDamage(unsigned int amount) {
   this->_damage -= amount;
   cout << "Scavtrap " << this->_name << " took " << amount << " points of damage" << endl;

}

void ScavTrap::beRepaired(unsigned int amount) {
   if (this->_hp = 0 || this->_energy != 0)
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

void    guardGate() {
   cout << "Scavtrap  is in guard mode" << endl;
}


   
   