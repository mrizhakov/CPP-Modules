/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrizakov <mrizakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 19:01:04 by mrizakov          #+#    #+#             */
/*   Updated: 2024/02/28 17:48:59 by mrizakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"


Cat::Cat(void) : _type("Cat") {
   std::cout << this->_type << " object of type is instantiated" << std::endl;
}

Cat::~Cat(void) {
   std::cout << this->_type << " object is destroyed" << std::endl;
}

Cat::Cat(const Cat& other)
{
   *this = other;
   std::cout << this->_type << " object is instantiated using the copy constructor" << std::endl;
}

Cat&    Cat::operator=(const Cat& other)
{
   this->_type = other._type;
   std::cout << this->_type << " is instantiated using the assignment constructor" << std::endl;
   return *this;
}

void Cat::makeSound(void) const {
   std::cout << this->_type << " object is doing a generic animal sound" << std::endl;
}

std::string Cat::getType(void) const {
   return (this->_type);
}
