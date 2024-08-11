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

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void): AForm("ShrubberyCreationForm", 145, 137) {
   this->_target = "none";
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target): AForm("ShrubberyCreationForm", 145, 137) {
   this->_target = target;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other): AForm("ShrubberyCreationForm", 145, 137)
{
   *this = other;
}

ShrubberyCreationForm&    ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
   this->_target = other._target;
   return *this;
}

void    ShrubberyCreationForm::action(void) const {
   std::ofstream outputFile((this->_target + "_shrubbery").c_str());
   if (!outputFile)
   {
      std::cerr << "Can't create/open file : " << this->_target + "_shrubbery" <<std::endl;
      return ;
   }
   outputFile <<
                  "      / _-_\\ \n"
                  "    /~~   ~~~\\ \n"
                  " /~~         ~~\\ \n"
                  "{               } \n"
                  " \\  _-     -_  / \n"
                  "   ~  \\ //  ~ \n"
                  "_- -   | | _- _ \n"
                  "  _ -  | |   -_ \n"
                  "      // \\ \n"
                  << std::endl;
}
