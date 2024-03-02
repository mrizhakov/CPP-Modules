/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrizakov <mrizakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 19:01:04 by mrizakov          #+#    #+#             */
/*   Updated: 2024/03/02 18:35:11 by mrizakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"


WrongCat::WrongCat(void) : _type("WrongCat") {
   std::cout << this->_type << " object is instantiated" << std::endl;
}

WrongCat::~WrongCat(void) {
   std::cout << this->_type << " object is destroyed" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other)
{
   *this = other;
   std::cout << this->_type << " object is instantiated using the copy constructor" << std::endl;
}

WrongCat&    WrongCat::operator=(const WrongCat& other)
{
   this->_type = other._type;
   std::cout << this->_type << " is instantiated using the assignment constructor" << std::endl;
   return *this;
}

void WrongCat::makeSound(void) const {
   std::cout << this->_type << " says meow meow!" << std::endl;
}

std::string WrongCat::getType(void) const {
   return (this->_type);
}

