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

#include "AForm.hpp"

AForm::AForm(const std::string name, bool formSigned, unsigned int const grade_to_sign, unsigned int const grade_to_execute):
 _name(name), _formSigned(formSigned), _grade_to_sign(grade_to_sign), _grade_to_execute(grade_to_execute) {
   if (_grade_to_sign < 1 || _grade_to_execute < 1)
      throw GradeTooHighException();
   if (_grade_to_sign > 150 || _grade_to_execute > 150)
      throw GradeTooLowException();
   std::cout << "Form called "<< _name << " instantiated\n";
}

AForm::~AForm(void) {
   std::cout << "Form called "<< _name << " destroyed\n";
}

AForm::AForm(const AForm& other)
{
   *this = other;
   std::cout << "Form called "<< _name << " is instantiated using the copy constructor" << std::endl;
}

AForm&    AForm::operator=(const AForm& other)
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

const char* AForm::GradeTooHighException::what() const throw() {
   return "Grade too high!\n";
}

const char* AForm::GradeTooLowException::what() const throw() {
   return "Grade too low!\n";
}

std::string const AForm::getName(void) const {
   return (this->_name);
}

unsigned int      AForm::getGradeToSign(void) const {
   return (this->_grade_to_sign);
}

unsigned int      AForm::getGradeToExecute(void) const {
   return (this->_grade_to_execute);
}

bool              AForm::getSigned(void) const {
   return (this->_formSigned);
}

void              AForm::beSigned(const Bureaucrat& b)
{
   if (_grade_to_sign <= b.getGrade())
      throw GradeTooLowException();
   this->_formSigned = true;
   std::cout << "Form "<< _name << " signed by " << b.getName() << std::endl;
}

std::ostream& operator<<(std::ostream& os, const AForm& f) {
   os << "Form: " << f.getName() << " is signed " << f.getSigned() << ", requires grade to sign: " << f.getGradeToSign() << " and grade to execute " << f.getGradeToExecute() << std::endl;
   return os;
}
