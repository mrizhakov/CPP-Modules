/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                       :+:      :+:    :+:   */
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
#include <Bureaucrat.hpp>

class Bureaucrat;

class ShrubberyCreationForm : public AForm 
{
    private:
        std::string             _name;
        bool                    _formSigned;
        unsigned int            _grade_to_sign;
        unsigned int            _grade_to_execute;
        std::string             _target;


    public:
        ShrubberyCreationForm(const std::string target);
        ~ShrubberyCreationForm(void);
        ShrubberyCreationForm(const ShrubberyCreationForm& other);
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);

        // class GradeTooHighException : public std::exception {
        // public:
        //     virtual const char* what() const throw();
        // };
        // class GradeTooLowException : public std::exception {
        // public:
        //     virtual const char* what() const throw() ;
        // };

        // void                    beSigned(const Bureaucrat& b);
        
        // std::string const       getName(void) const;
        // unsigned int            getGradeToSign(void) const;
        // unsigned int            getGradeToExecute(void) const;
        // bool                    getSigned(void) const;
        virtual void    execute(Bureaucrat const &executor) const; 
};
std::ostream& operator<<(std::ostream& os, const AForm& f);