/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrizakov <mrizakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 15:13:31 by mrizakov          #+#    #+#             */
/*   Updated: 2024/02/05 20:11:42 by mrizakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP


#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <limits>

class Zombie {
    
    public:
    Zombie(void);
    Zombie(std::string str);
    ~Zombie(void);
    void set_name(std::string name);
    void announce(void);
    
    private:
    std::string _zombie_name;
};

Zombie  *newZombie(std::string name);
void    randomChump(std::string name);

#endif // ZOMBIE_HPP