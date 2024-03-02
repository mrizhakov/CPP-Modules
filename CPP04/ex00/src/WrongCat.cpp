/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrizakov <mrizakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 19:01:04 by mrizakov          #+#    #+#             */
/*   Updated: 2024/03/02 21:43:34 by mrizakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"


WrongCat::WrongCat(void) {
   this->_type = "WrongCat";
   std::cout << "WrongCat object is instantiated" << std::endl;
}

WrongCat::~WrongCat(void) {
   std::cout << "WrongCat object is destroyed" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other)
{
   *this = other;
   std::cout << "WrongCat object is instantiated using the copy constructor" << std::endl;
}

WrongCat&    WrongCat::operator=(const WrongCat& other)
{
   this->_type = other._type;
   std::cout << "WrongCat is instantiated using the assignment constructor" << std::endl;
   return *this;
}

void WrongCat::makeSound(void) const {
   std::cout << this->getType() << " says meow meow!" << std::endl;
}

