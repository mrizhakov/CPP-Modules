/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongDog.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrizakov <mrizakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 19:01:04 by mrizakov          #+#    #+#             */
/*   Updated: 2024/03/02 21:43:37 by mrizakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongDog.hpp"


WrongDog::WrongDog(void) {
   this->_type = "WrongDog";
   std::cout << "WrongDog object is instantiated" << std::endl;
}

WrongDog::~WrongDog(void) {
   std::cout << "WrongDog object is destroyed" << std::endl;
}

WrongDog::WrongDog(const WrongDog& other)
{
   *this = other;
   std::cout << "WrongDog object is instantiated using the copy constructor" << std::endl;
}

WrongDog&    WrongDog::operator=(const WrongDog& other)
{
   this->_type = other._type;
   std::cout << "WrongDog is instantiated using the assignment constructor" << std::endl;
   return *this;
}

void WrongDog::makeSound(void) const {
   std::cout << this->getType() << " says woof woof!" << std::endl;
}

