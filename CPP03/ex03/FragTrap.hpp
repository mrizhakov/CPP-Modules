/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrizakov <mrizakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 19:01:08 by mrizakov          #+#    #+#             */
/*   Updated: 2024/02/24 18:16:54 by mrizakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef    FRAGTRAP_HPP
#define    FRAGTRAP_HPP

#include <iostream>
#include <string>
#include "ClapTrap.hpp"

using std::cout;
using std::endl;
using std::string;


class FragTrap : virtual public ClapTrap
{
    public:
        FragTrap(void);
        FragTrap(std::string name);
        ~FragTrap(void);
        FragTrap(const FragTrap& other);
        FragTrap& operator=(const FragTrap& other);

        // void    attack(const string& target);
        // void    takeDamage(unsigned int amount);
        // void    beRepaired(unsigned int amount);
        void    highFivesGuys(void);

    protected:
        string          _name;
        unsigned int    _hp;
        unsigned int    _energy;
        unsigned int    _damage;
};

#endif
