/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrizakov <mrizakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 19:01:04 by mrizakov          #+#    #+#             */
/*   Updated: 2024/02/24 16:59:18 by mrizakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

using std::cout;
using std::endl;
using std::string;

ClapTrap::ClapTrap(void) :_name("no name"), _hp(10), _energy(10), _damage(0)  {
   cout << "Claptrap " << this->_name << " is alive" << endl;
}

ClapTrap::ClapTrap(string name) {
   this->_name =  name;
   this->_hp =  10;
   this->_energy =  10;
   this->_damage =  0;
   cout << "Claptrap " << this->_name << " is alive" << endl;
}

ClapTrap::~ClapTrap(void) {
   cout << "Claptrap " << _name << " is unalive" << endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
   *this = other;
   cout << "Claptrap " << this->_name << " is alive" << endl;
}

ClapTrap&    ClapTrap::operator=(const ClapTrap& other)
{
   this->_name = other._name;
   this->_hp = other._hp;
   this->_energy = other._energy;
   cout << "Claptrap " << this->_name << " is alive" << endl;
   return *this;
}

void ClapTrap::attack(const string& target) {
   if (this->_hp <= 0 || this->_energy <= 0)
      cout << "Claptrap " << this->_name << " can't attack because it's energy or hp ar low" << endl;
   else
   {
      this->_energy--;
      cout << this->_name << " attacked " << target << " and did " << this->_damage << " damage" << endl;
   }
   if (this->_energy < 0)
      this->_energy = 0;
}

void ClapTrap::takeDamage(unsigned int amount) {
   this->_hp -= amount;
   if (this->_hp < 0)
      this->_hp = 0;
   cout << "Claptrap " << this->_name << " took " << amount << " points of damage" << endl;

}

void ClapTrap::beRepaired(unsigned int amount) {
   if (this->_hp <= 0 || this->_energy <= 0)
      cout << "Claptrap " << this->_name << " cant repair itself, because it's energy or hp ar low" << endl;
   else
   {
      this->_energy--;
      this->_hp += amount;
      cout << "Claptrap " << this->_name << " repaired itself"<< endl;
   }
}

void    guardGate() {
   cout << "Claptrap  is in guard mode" << endl;
}


   
   
