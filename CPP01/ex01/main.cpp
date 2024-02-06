/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrizakov <mrizakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 15:13:37 by mrizakov          #+#    #+#             */
/*   Updated: 2024/02/06 21:15:21 by mrizakov         ###   ########.fr       */
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
    Zombie* horde = zombieHorde(5, "chussi");
    horde->announce();
    horde[0].announce();
    horde[1].announce();
    horde[2].announce();
    horde[3].announce();
    horde[4].announce();
    delete [] horde;
    return(0);
}