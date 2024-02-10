/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrizakov <mrizakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 15:13:31 by mrizakov          #+#    #+#             */
/*   Updated: 2024/02/10 13:25:48 by mrizakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP


#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <limits>


class Weapon {
    
    public:
    Weapon(void);
    Weapon(std::string type);
    ~Weapon(void);
    
    const std::string getType(void) const;
    void        setType(std::string str);
    
    private:
    std::string _type;
};

#endif // WEAPON_HPP