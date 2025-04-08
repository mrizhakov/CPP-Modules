/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrizakov <mrizakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 01:07:18 by mrizakov          #+#    #+#             */
/*   Updated: 2025/04/09 01:07:24 by mrizakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Base.hpp"

Base::Base(void) {}

Base::~Base(void) {}

Base::Base(const Base& other)
{
   (void)other;
   *this = other;
}

Base&    Base::operator=(const Base& other)
{
   (void)other;
   return *this;
}