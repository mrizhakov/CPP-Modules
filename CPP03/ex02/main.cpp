/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrizakov <mrizakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 15:13:37 by mrizakov          #+#    #+#             */
/*   Updated: 2024/02/23 13:55:34 by mrizakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"


int main(void)
{
    
    // ClapTrap a;
    // ClapTrap();
    // ClapTrap b("Very big claptrap");

    // b.attack("my precious");
    // b.takeDamage(2);
    // b.beRepaired(2);

    ScavTrap e;
    ScavTrap ();
    ScavTrap d("Tiny ScavTrap");
    d.attack("my precious");
    d.takeDamage(2);
    d.beRepaired(2);
    ScavTrap f = d;


    
    return(0);
}

