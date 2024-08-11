/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrizakov <mrizakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 19:01:04 by mrizakov          #+#    #+#             */
/*   Updated: 2024/02/28 17:48:59 by mrizakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern(void) {
   std::cout << "Intern spawned\n";
}

Intern::~Intern(void) {
   std::cout << "Intern unspawned\n";
}

Intern::Intern(const Intern& other)
{
   *this = other;
   std::cout << "Intern object is instantiated using the copy constructor" << std::endl;
}

Intern&    Intern::operator=(const Intern& other)
{
   (void)other;
   std::cout << "Intern object is instantiated using the assignment constructor" << std::endl;
   return *this;
}

AForm *makeShrubberyCreationForm(std::string const target)
{
	return (new ShrubberyCreationForm(target));
}

AForm *makeRobotomyRequestForm(std::string const target)
{
	return (new RobotomyRequestForm(target));
}

AForm *makePresidentialPardonForm(std::string const target)
{
	return (new PresidentialPardonForm(target));
}

AForm* Intern::makeForm(std::string formName, std::string target)
{
   int i = 0;
   std::string formArray[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
   AForm *(*function[3])(const std::string target) = {makeShrubberyCreationForm, makeRobotomyRequestForm, makePresidentialPardonForm};
   while (i != 2)
   {
      if (formName == formArray[i])
      {
         std::cout << "Intern creates " << formName << std::endl;
         return function[i](target);
      } 
      i++;
   }
   throw FormCantBeCreated();
   std::cout << "Intern can't create form " << formName << " since it is not a valid form" << std::endl;
   
   return (NULL);
}

const char* Intern::FormCantBeCreated::what() const throw() {
   return "Form name incorrect!\n";
}



