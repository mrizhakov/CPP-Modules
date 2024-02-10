/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrizakov <mrizakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 15:13:31 by mrizakov          #+#    #+#             */
/*   Updated: 2024/02/10 15:07:28 by mrizakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP


#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <limits>
#include "Weapon.hpp"


class HumanA {
    
    public:
        HumanA(std::string name, Weapon &weapon);
        ~HumanA(void);
        void setName(std::string name);
        void attack(void) const;
    
    private:
        std::string _name;
        Weapon      &_weapon;
};

#endif // HUMANA_HPP