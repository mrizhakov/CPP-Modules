/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrizakov <mrizakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 15:13:31 by mrizakov          #+#    #+#             */
/*   Updated: 2024/02/09 20:10:18 by mrizakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP


#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <limits>
#include "Weapon.hpp"


class HumanB {
    
    public:
        HumanB(void);
        HumanB(std::string name);
        ~HumanB(void);
        void setName(std::string name);
        void setWeapon(Weapon weapon);
        void attack(void) const;
    
    private:
        std::string _name;
        Weapon      _weapon;
};

#endif // HUMANB_HPP