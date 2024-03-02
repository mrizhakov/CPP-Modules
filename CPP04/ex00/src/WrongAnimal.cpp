/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrizakov <mrizakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 19:01:04 by mrizakov          #+#    #+#             */
/*   Updated: 2024/02/28 17:48:59 by mrizakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) {
   this->_type = "WrongAnimal";
   std::cout << "WrongAnimal object is instantiated" << std::endl;
}

WrongAnimal::~WrongAnimal(void) {
   std::cout << "WrongAnimal object is destroyed" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other)
{
   *this = other;
   std::cout << "WrongAnimal object is instantiated using the copy constructor" << std::endl;
}

WrongAnimal&    WrongAnimal::operator=(const WrongAnimal& other)
{
   this->_type = other._type;
   std::cout << "WrongAnimal object is instantiated using the assignment constructor" << std::endl;
   return *this;
}

void WrongAnimal::makeSound(void) const {
   std::cout << "WrongAnimal sound" << std::endl;
}

std::string WrongAnimal::getType(void) const {
   return (this->_type);
}

