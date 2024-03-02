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
#include "Brain.hpp"


Cat::Cat(void) {
   this->_type = "Cat";
   std::cout << "Cat object is instantiated" << std::endl;
   this->_animalBrain = new Brain();
}

Cat::~Cat(void) {
   delete this->_animalBrain;
   std::cout << "Cat object is destroyed" << std::endl;
}

Cat::Cat(const Cat& other)
{
   this->_animalBrain = new Brain();
   int i = 0;
   while (i != 99)
   {
      this->_animalBrain->_ideas[i] = other._animalBrain->_ideas[i];
      i++;
   }
   this->_type = other._type;
   std::cout << "Cat object is instantiated using the copy constructor" << std::endl;
}

Cat&    Cat::operator=(const Cat& other)
{
   int i = 0;
   while (i != 99)
   {
      this->_animalBrain->_ideas[i] = other._animalBrain->_ideas[i];
      i++;
   }
   this->_type = other._type;
   std::cout << "Cat is instantiated using the assignment constructor" << std::endl;
   return *this;
}

void Cat::makeSound(void) const {
   std::cout << this->_type << " says meow meow!" << std::endl;
}

void Cat::giveIdeas(std::string thought, unsigned int i) {
   this->_animalBrain->_ideas[i] = thought;
}

std::string Cat::checkIdeas(unsigned int i) {
   std::cout << this->_type << " is thinking " << this->_animalBrain->_ideas[i] << std::endl;
   return this->_animalBrain->_ideas[i];
}
