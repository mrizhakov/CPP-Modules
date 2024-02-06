/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrizakov <mrizakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 15:13:37 by mrizakov          #+#    #+#             */
/*   Updated: 2024/02/06 20:04:18 by mrizakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sstream>

#include "Zombie.hpp"


Zombie* zombieHorde(int N, std::string name){
    int i = 0;
    std::string name_with_modifier;
    std::stringstream ss;
    Zombie *horde = new Zombie[N];
    while (i != N)
    {
        ss << i;
        name_with_modifier = name + " " + ss.str();
        // horde[i] = Zombie(name);
        horde[i].set_name(name_with_modifier);


        i++;
    }
    return(horde);
}