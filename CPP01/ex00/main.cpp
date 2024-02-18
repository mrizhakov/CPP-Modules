/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrizakov <mrizakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 15:13:37 by mrizakov          #+#    #+#             */
/*   Updated: 2024/02/12 16:23:50 by mrizakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <limits>
#include "Zombie.hpp"



int main(void)
{
    
    Zombie().announce();
    Zombie().announce();

    
    Zombie(hallo1);
    
    hallo1.announce();
    randomChump("bye");
    Zombie *totallyNewZombie = newZombie("totally new zombie");
    totallyNewZombie->announce();
    delete totallyNewZombie;
    
    return(0);
}

