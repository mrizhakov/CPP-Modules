/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrizakov <mrizakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 19:01:04 by mrizakov          #+#    #+#             */
/*   Updated: 2024/02/24 18:10:55 by mrizakov         ###   ########.fr       */
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
   this->_name = other._name;
   this->_hp = other._hp;
   this->_energy = other._energy;
   cout << "Fragtrap " << this->_name << " is alive" << endl;
   return *this;
}

void  FragTrap::highFivesGuys(void) {
   cout << "Fragtrap " << this->_name << " is high fiving" << endl;
}


   
   
