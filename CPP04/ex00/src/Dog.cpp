/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrizakov <mrizakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 19:01:04 by mrizakov          #+#    #+#             */
/*   Updated: 2024/02/28 17:48:59 by mrizakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"


Dog::Dog(void) {
   this->_type = "Dog";
   std::cout << "Dog object is instantiated" << std::endl;
}

Dog::~Dog(void) {
   std::cout << "Dog object is destroyed" << std::endl;
}

Dog::Dog(const Dog& other)
{
   *this = other;
   std::cout << "Dog object is instantiated using the copy constructor" << std::endl;
}

Dog&    Dog::operator=(const Dog& other)
{
   this->_type = other._type;
   std::cout << "Dog is instantiated using the assignment constructor" << std::endl;
   return *this;
}

void Dog::makeSound(void) const {
   std::cout << this->_type << " says woof woof!" << std::endl;
}
