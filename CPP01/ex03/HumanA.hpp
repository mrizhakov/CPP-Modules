/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrizakov <mrizakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 15:13:31 by mrizakov          #+#    #+#             */
/*   Updated: 2024/02/07 21:00:06 by mrizakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP


#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <limits>

class HumanA {
    
    public:
    HumanA(std::string name, Weapon weapon);
    ~HumanA(void);
    void set_name(std::string name);
    
    private:
    std::string _name;
    void Weapon(void);
};

#endif // HUMANA_HPP