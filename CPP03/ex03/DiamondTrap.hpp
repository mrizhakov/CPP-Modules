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

#pragma once
// #ifndef    DIAMONDTRAP_HPP
// #define    DIAMONDTRAP_HPP

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

        using   ScavTrap::attack; //(const string& target);
        using   ClapTrap::beRepaired; //(const string& target);
        using   ClapTrap::takeDamage;
        void    whoAmI(void);
        void    setName(string name);

    private:
        string          _name;
        using           FragTrap::_hp;
        using           ScavTrap::_energy;
        using           FragTrap::_damage;
};

// #endif
