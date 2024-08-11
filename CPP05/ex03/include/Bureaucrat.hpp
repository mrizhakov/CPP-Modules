/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrizakov <mrizakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 19:01:08 by mrizakov          #+#    #+#             */
/*   Updated: 2024/02/26 18:38:02 by mrizakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>
#include <stdexcept>
#include <iostream>
#include <AForm.hpp>

class AForm;

class Bureaucrat
{
    private:
        std::string  _name;
        unsigned int _grade;
        
        
    public:
        Bureaucrat(void);
        Bureaucrat(const std::string name, unsigned int grade);
        ~Bureaucrat(void);
        Bureaucrat(const Bureaucrat& other);
        Bureaucrat& operator=(const Bureaucrat& other);

        class GradeTooHighException : public std::exception {
        public:
            virtual const char* what() const throw();
        };
        class GradeTooLowException : public std::exception {
        public:
            virtual const char* what() const throw() ;
        };


        std::string const   getName(void) const;
        unsigned int        getGrade(void) const;
        void                incrementGrade(void);
        void                decrementGrade(void);
        void                signForm(AForm &f);
        void                executeForm(AForm const & form) const;
};
std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);