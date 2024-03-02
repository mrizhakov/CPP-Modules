/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrizakov <mrizakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 19:01:04 by mrizakov          #+#    #+#             */
/*   Updated: 2024/02/28 17:48:59 by mrizakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void) : _type("Animal") {
   std::cout << this->_type << " object is instantiated" << std::endl;
}

Animal::~Animal(void) {
   std::cout << this->_type << " object is destroyed" << std::endl;
}

Animal::Animal(const Animal& other)
{
   *this = other;
   std::cout << this->_type << " object is instantiated using the copy constructor" << std::endl;
}

Animal&    Animal::operator=(const Animal& other)
{
   this->_type = other._type;
   std::cout << this->_type << " object is instantiated using the assignment constructor" << std::endl;
   return *this;
}

void Animal::makeSound(void) const {
   std::cout << this->_type << " object is doing a generic animal sound" << std::endl;
}

std::string Animal::getType(void) const {
   return (this->_type);
}

void Animal::makeNoise(void) const {
   std::cout << this->_type << " is making generic noises" << std::endl;
}
