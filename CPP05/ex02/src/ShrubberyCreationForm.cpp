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

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target): _target(target) {
_grade_to_sign = 145;
_grade_to_execute = 137;

   std::cout << "Form called "<< _name << " instantiated\n";
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {
   std::cout << "Form called "<< _name << " destroyed\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
{
   *this = other;
   std::cout << "Form called "<< _name << " is instantiated using the copy constructor" << std::endl;
}

ShrubberyCreationForm&    ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
   if (this != &other)
   {
      this->_name = other._name;
      this->_formSigned = other._formSigned;
      this->_grade_to_sign = other._grade_to_sign;
      this->_grade_to_execute = other._grade_to_execute;
   }

   std::cout << "Form called "<< _name << " is instantiated using the assignment constructor" << std::endl;
   return *this;
}

// const char* ShrubberyCreationForm::GradeTooHighException::what() const throw() {
//    return "Grade too high!\n";
// }

// const char* ShrubberyCreationForm::GradeTooLowException::what() const throw() {
//    return "Grade too low!\n";
// }

// std::string const ShrubberyCreationForm::getName(void) const {
//    return (this->_name);
// }

// unsigned int      AForm::getGradeToSign(void) const {
//    return (this->_grade_to_sign);
// }

// unsigned int      AForm::getGradeToExecute(void) const {
//    return (this->_grade_to_execute);
// }

// bool              AForm::getSigned(void) const {
//    return (this->_formSigned);
// }

// void              AForm::beSigned(const Bureaucrat& b)
// {
//    if (_grade_to_sign <= b.getGrade())
//       throw GradeTooLowException();
//    this->_formSigned = true;
//    std::cout << "Form "<< _name << " signed by " << b.getName() << std::endl;
// }
virtual void    execute(Bureaucrat const &executor) const {

}


std::ostream& operator<<(std::ostream& os, const AForm& f) {
   os << "Form: " << f.getName() << " is signed " << f.getSigned() << ", requires grade to sign: " << f.getGradeToSign() << " and grade to execute " << f.getGradeToExecute() << std::endl;
   return os;
}
