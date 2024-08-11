/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                       :+:      :+:    :+:   */
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
// #include <AForm.hpp>

class AForm;

class Intern
{
    // private:
    //     AForm* forms[3];
        
    public:
        Intern(void);
        ~Intern(void);
        Intern(const Intern& other);
        Intern& operator=(const Intern& other);
        
        AForm* makeForm(std::string formName, std::string target);
        class FormCantBeCreated : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
};
