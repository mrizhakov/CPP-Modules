/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrizakov <mrizakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 19:01:08 by mrizakov          #+#    #+#             */
/*   Updated: 2024/02/24 18:03:42 by mrizakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef    SCAVTRAP_HPP
#define    SCAVTRAP_HPP

#include <iostream>
#include <string>
#include "ClapTrap.hpp"

using std::cout;
using std::endl;
using std::string;


class ScavTrap : public ClapTrap
{
    public:
        ScavTrap(void);
        ScavTrap(std::string name);
        ~ScavTrap(void);
        ScavTrap(const ScavTrap& other);
        ScavTrap& operator=(const ScavTrap& other);

        void    guardGate(void);

    private:
        string          _name;
        unsigned int    _hp;
        unsigned int    _energy;
        unsigned int    _damage;
};

#endif
