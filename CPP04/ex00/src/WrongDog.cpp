/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongDog.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrizakov <mrizakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 19:01:04 by mrizakov          #+#    #+#             */
/*   Updated: 2024/03/02 18:35:15 by mrizakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongDog.hpp"


WrongDog::WrongDog(void) : _type("WrongDog") {
   std::cout << this->_type << " object is instantiated" << std::endl;
}

WrongDog::~WrongDog(void) {
   std::cout << this->_type << " object is destroyed" << std::endl;
}

WrongDog::WrongDog(const WrongDog& other)
{
   *this = other;
   std::cout << this->_type << " object is instantiated using the copy constructor" << std::endl;
}

WrongDog&    WrongDog::operator=(const WrongDog& other)
{
   this->_type = other._type;
   std::cout << this->_type << " is instantiated using the assignment constructor" << std::endl;
   return *this;
}

void WrongDog::makeSound(void) const {
   std::cout << this->_type << " says woof woof!" << std::endl;
}

std::string WrongDog::getType(void) const {
   return (this->_type);
}
