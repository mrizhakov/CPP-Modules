/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Target.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrizakov <mrizakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 19:01:15 by mrizakov          #+#    #+#             */
/*   Updated: 2024/02/18 19:01:16 by mrizakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Target.hpp"

Target::Target(void) {}

Target::~Target(void) {}

Target::Target(const Target& other)
{
   *this = other;
}

Target&    Target::operator=(const Target& other)
{
   (void)other;
   return *this;
}
