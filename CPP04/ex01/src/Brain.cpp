/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrizakov <mrizakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 19:01:04 by mrizakov          #+#    #+#             */
/*   Updated: 2024/02/28 17:48:59 by mrizakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void) {
   std::cout << "Brain object is instantiated" << std::endl;
}

Brain::~Brain(void) {
   std::cout << "Brain object is destroyed" << std::endl;
}

Brain::Brain(const Brain& other)
{
   int i = 0;
   while (i != 99)
   {
      this->_ideas[i] = other._ideas[i];
      i++;
   }
   std::cout << "Brain object is instantiated using the copy constructor" << std::endl;
}

Brain&    Brain::operator=(Brain& other)
{
   int i = 0;
   while (i != 99)
   {
      this->_ideas[i] = other._ideas[i];
      i++;
   }
   std::cout << "Brain object is instantiated using the assignment constructor" << std::endl;
   return *this;
}
