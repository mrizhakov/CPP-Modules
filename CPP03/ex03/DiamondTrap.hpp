/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrizakov <mrizakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 19:01:08 by mrizakov          #+#    #+#             */
/*   Updated: 2024/02/23 14:17:37 by mrizakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef    DIAMONDTRAP_HPP
#define    DIAMONDTRAP_HPP

#include <iostream>
#include <string>
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "ClapTrap.hpp"



using std::cout;
using std::endl;
using std::string;

class DiamondTrap : public FragTrap, public ScavTrap
{
    public:
        //DiamondTrap(void);
        DiamondTrap(std::string name);
        ~DiamondTrap(void);
        DiamondTrap(const DiamondTrap& other);
        DiamondTrap& operator=(const DiamondTrap& other);

        // void    attack(const string& target);
        // void    takeDamage(unsigned int amount);
        // void    beRepaired(unsigned int amount);
        // void    highFivesGuys(void);
        using   ScavTrap::attack;
        void    whoAmI(void);

    private:
        string          _name;
        unsigned int    _hp;
        unsigned int    _energy;
        unsigned int    _damage;
};

#endif
