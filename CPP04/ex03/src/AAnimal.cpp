/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrizakov <mrizakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 19:01:04 by mrizakov          #+#    #+#             */
/*   Updated: 2024/02/28 17:48:59 by mrizakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"


// AAnimal::AAnimal(void) {
//    this->_type = "AAnimal";
//    std::cout << "AAnimal object is instantiated" << std::endl;
// }

// AAnimal::~AAnimal(void) {
//    std::cout << "AAnimal object is destroyed" << std::endl;
// }

AMateria::AMateria(const AMateria& other)
{
   *this = other;
   std::cout << "AAnimal object is instantiated using the copy constructor" << std::endl;
}

AAnimal&    AAnimal::operator=(const AAnimal& other)
{
   this->_type = other._type;
   std::cout << "AAnimal object is instantiated using the assignment constructor" << std::endl;
   return *this;
}

void AAnimal::makeSound(void) const {
   std::cout << this->_type << " object is doing a generic animal sound" << std::endl;
}

std::string AAnimal::getType(void) const {
   return (this->_type);
}



