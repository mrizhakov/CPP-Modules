/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrizakov <mrizakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 15:13:37 by mrizakov          #+#    #+#             */
/*   Updated: 2024/02/26 18:36:27 by mrizakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"


using std::cout;
using std::endl;
using std::string;


int main(void)
{
    DiamondTrap diamond("diamond");
    diamond.attack("victim");
    diamond.takeDamage(2);
    diamond.whoAmI();

    diamond.takeDamage(200);
    diamond.whoAmI();
    diamond.beRepaired(100);


    diamond.attack("target");
    diamond.whoAmI();


    diamond.guardGate();
    diamond.highFivesGuys();
    diamond.whoAmI();
    return(0);
}

