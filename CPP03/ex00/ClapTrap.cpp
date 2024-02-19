/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrizakov <mrizakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 19:01:04 by mrizakov          #+#    #+#             */
/*   Updated: 2024/02/18 19:01:05 by mrizakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) {}

ClapTrap::~ClapTrap(void) {}

ClapTrap::ClapTrap(const ClapTrap& other)
{
   *this = other;
}

ClapTrap&    ClapTrap::operator=(const ClapTrap& other)
{
   (void)other;
   return *this;
}
