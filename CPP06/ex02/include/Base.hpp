/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrizakov <mrizakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 01:07:07 by mrizakov          #+#    #+#             */
/*   Updated: 2025/04/09 17:56:53 by mrizakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stdint.h>
#include <iostream>
#include <cstdlib>
#include <typeinfo>    // std::bad_cast, std::bad_typeid

class Base
{
    protected:        
        Base(const Base& other);

        
    
    private:        
        Base& operator=(const Base& other);
        
        
        
    public:
        Base(void);
        virtual ~Base();
        
};

Base * generate(void);
void identify(Base* p);
void identify(Base& p);
