/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrizakov <mrizakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 19:01:04 by mrizakov          #+#    #+#             */
/*   Updated: 2024/02/22 20:52:25 by mrizakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

using std::cout;
using std::endl;
using std::string;

ClapTrap::ClapTrap(void) :_name("no name")  {
   cout << "Claptrap " << this->_name << " is alive" << endl;
}

ClapTrap::ClapTrap(string name) {
   this->_name =  name;
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
   (void)other;
   cout << "Claptrap " << this->_name << " is alive" << endl;
   return *this;
}

void ClapTrap::attack(const string& target) {
   unsigned int damage = 2;
   if (this->_hp != 0 || this->_energy != 0)
   {
      this->_energy--;
      cout << this->_name << " attacked " << target << " and did " << damage << endl;
   }
   else
      cout << "Claptrap " << this->_name << " can't attack because it's energy or hp ar low" << endl;
   // if (this->_hp != 0 || this->_energy != 0)
   // {
   //    this->_energy--;
   //    *target.takeDamage(damage);
   //    cout << "Claptrap " << this->_name << " attacks " << target.getName() << " causing " << damage << " points of damage!" << endl;
   // }
   // else
   //    cout << "Claptrap " << this->_name << " can't attack because it's energy or hp ar low" << target.getName() << " causing " << damage << " points of damage!" << endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
   this->_damage -= amount;
   cout << "Claptrap " << this->_name << " took " << amount << " points of damage" << endl;

}

void ClapTrap::beRepaired(unsigned int amount) {
   if (this->_hp != 0 || this->_energy != 0)
   {
      this->_energy--;
      this->_hp += amount;
      if (this->_hp > 10)
         this->_hp = 10;
      cout << "Claptrap " << this->_name << " repaired itself"<< endl;
   }
   else
      cout << "Claptrap " << this->_name << " can't attack because it's energy or hp ar low" << endl;
}

   
   
