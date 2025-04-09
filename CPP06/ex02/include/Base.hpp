/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrizakov <mrizakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 01:07:07 by mrizakov          #+#    #+#             */
/*   Updated: 2025/04/09 22:09:24 by mrizakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stdint.h>
#include <iostream>
#include <cstdlib>
// #include <typeinfo>

class Base
{
    protected:        
        Base(const Base& other);
        Base(void);
        
    private:        
        Base& operator=(const Base& other);
        
    public:    
        virtual ~Base();
        
};

Base * generate(void);
void identify(Base* p);
void identify(Base& p);
