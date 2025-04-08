/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrizakov <mrizakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 01:07:07 by mrizakov          #+#    #+#             */
/*   Updated: 2025/04/09 01:13:36 by mrizakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stdint.h>
#include <iostream>



class Base
{
    private:        
        Base(void);
        Base(const Base& other);
        Base& operator=(const Base& other);
        
        Base * generate(void);
        void identify(Base* p);
        void identify(Base& p);
        
    public:
        virtual ~Base(void);
        
};

