/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrizakov <mrizakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 15:13:37 by mrizakov          #+#    #+#             */
/*   Updated: 2024/02/24 17:00:27 by mrizakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"

int main(void)
{
    
    ClapTrap a;
    ClapTrap b("Very big claptrap");

    b.attack("my precious");
    b.takeDamage(9);
    b.attack("my precious");
    
    b.beRepaired(2);

    b.takeDamage(10);

    b.beRepaired(2);

    


    
    return(0);
}

