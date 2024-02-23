/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrizakov <mrizakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 19:01:04 by mrizakov          #+#    #+#             */
/*   Updated: 2024/02/23 14:18:38 by mrizakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

using std::cout;
using std::endl;
using std::string;

FragTrap::FragTrap(void) : ClapTrap(), _name("no name")  {
   this->_hp =  100;
   this->_energy =  100;
   this->_damage =  30;
   cout << "Fragtrap " << this->_name << " is alive" << endl;
}

FragTrap::FragTrap(string name) : ClapTrap(name) {
   this->_name =  name;
   this->_hp =  100;
   this->_energy =  100;
   this->_damage =  30;
   cout << "Fragtrap " << this->_name << " is alive" << endl;
}

FragTrap::~FragTrap(void) {
   cout << "Fragtrap " << _name << " is unalive" << endl;
}

FragTrap::FragTrap(const FragTrap& other)
{
   *this = other;
   cout << "Fragtrap " << this->_name << " is alive" << endl;
}

FragTrap&    FragTrap::operator=(const FragTrap& other)
{
   (void)other;
   cout << "Fragtrap " << this->_name << " is alive" << endl;
   return *this;
}

void FragTrap::attack(const string& target) {
   unsigned int damage = 2;
   if (this->_hp != 0 || this->_energy != 0)
   {
      this->_energy--;
      cout << this->_name << " attacked " << target << " and did " << damage << endl;
   }
   else
      cout << "Fragtrap " << this->_name << " can't attack because it's energy or hp ar low" << endl;
}

void FragTrap::takeDamage(unsigned int amount) {
   this->_damage -= amount;
   cout << "Fragtrap " << this->_name << " took " << amount << " points of damage" << endl;

}

void FragTrap::beRepaired(unsigned int amount) {
   if (this->_hp != 0 || this->_energy != 0)
   {
      this->_energy--;
      this->_hp += amount;
      if (this->_hp > 10)
         this->_hp = 10;
      cout << "Fragtrap " << this->_name << " repaired itself"<< endl;
   }
   else
      cout << "Fragtrap " << this->_name << " can't attack because it's energy or hp ar low" << endl;
}

void  FragTrap::highFivesGuys(void) {
   cout << "Fragtrap " << this->_name << " is high fiving" << endl;
}


   
   
