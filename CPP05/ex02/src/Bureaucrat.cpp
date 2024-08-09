/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrizakov <mrizakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 19:01:04 by mrizakov          #+#    #+#             */
/*   Updated: 2024/02/28 17:48:59 by mrizakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string name, unsigned int grade): _name(name) {
   if (grade < 1)
      throw GradeTooHighException();
   if (grade > 150)
      throw GradeTooLowException();
   this->_grade = grade;
   std::cout << "Bureaucrat called "<< _name << " with grade " << _grade << " instantiated\n";
}

Bureaucrat::~Bureaucrat(void) {
   std::cout << "Bureaucrat called "<< _name << " with grade " << _grade << " destroyed\n";
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
{
   *this = other;
   std::cout << "Bureaucrat object is instantiated using the copy constructor" << std::endl;
}

Bureaucrat&    Bureaucrat::operator=(const Bureaucrat& other)
{
   if (this != &other)
   {
      this->_name = other._name;
      this->_grade = other._grade;
   }

   std::cout << "Bureaucrat object is instantiated using the assignment constructor" << std::endl;
   return *this;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
   return "Grade too high!\n";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
   return "Grade too low!\n";
}


std::string const Bureaucrat::getName(void) const {
   return (this->_name);
}

unsigned int Bureaucrat::getGrade(void) const {
   return (this->_grade);
}

void Bureaucrat::incrementGrade(void) {
   {
      if (this->_grade <= 1)
         throw GradeTooHighException();
      this->_grade--;
      std::cout << "Bureaucrat called "<< _name << " received a promotion! New grade " << _grade << std::endl;
   }
}

void Bureaucrat::decrementGrade(void) {
   {
      if (this->_grade >= 150)
         throw GradeTooLowException();
      this->_grade++;
      std::cout << "Bureaucrat called "<< _name << " received a demotion! New grade " << _grade << std::endl;
   }
}

void Bureaucrat::signForm(AForm &f) {
   try {
         f.beSigned(*this);
   } catch (std::exception &e) {
         std::cout << this->getName() << " couldn't sign " << f.getName() << " because " << e.what();
   }
   std::cout << this->_name << " signed "<< f.getName() << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b) {
   os << "Bureacrat: " << b.getName() << ", Grade: " << b.getGrade();
   return os;
}
