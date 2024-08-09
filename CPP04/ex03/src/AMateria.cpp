/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrizakov <mrizakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 19:01:04 by mrizakov          #+#    #+#             */
/*   Updated: 2024/03/03 15:27:59 by mrizakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"


// AMateria::AMateria(std::string const & type) {};

Amateria::AMateria(const AMateria& other) {
   *this = other;
};

AMateria::AMateria& operator=(const AMateria& other) {
   this->_type = other->_type;
   return *this;
};
// virtual ~AMateria(void) {}; //virtual?


std::string const & AMateria::getType(void) const {
   return this->_type;
};

AMateria* AMateria::clone() const {
   return (AMateria*)this;
}

void AMateria::use(ICharacter& target) {
   
};