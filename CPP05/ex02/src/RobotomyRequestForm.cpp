/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrizakov <mrizakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 19:01:04 by mrizakov          #+#    #+#             */
/*   Updated: 2024/02/28 17:48:59 by mrizakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm(void): AForm("RobotomyRequestForm", 72, 45) {
   this->_target = "none";
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target): AForm("RobotomyRequestForm", 72, 45) {
   this->_target = target;
}

RobotomyRequestForm::~RobotomyRequestForm(void) {
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other): AForm("RobotomyRequestForm", 72, 45)
{
   *this = other;
}

RobotomyRequestForm&    RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
   this->_target = other._target;
   return *this;
}

void    RobotomyRequestForm::action(void) const {

   std::cout << "Make drilling noises" << std::endl;
   std::srand(std::time(0));
   int randomNumber = (std::rand() % 2);
   if (randomNumber)
      std::cout << this->_target << " has been robotomized successfully" << std::endl;
   else
      std::cout << this->_target << " has failed" << std::endl;
   int i = 0;
   int tails = 0;
   int heads = 0;
   while (i != 1000)
   {
      int randomNumber = (std::rand() % 2);
      if (randomNumber)
         heads++;
      else
         tails++;
      i++;
   }
   std::cout << "Chances of robotimization today were " << heads << " to " << tails << std::endl;
}
