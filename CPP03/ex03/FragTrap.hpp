/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrizakov <mrizakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 19:01:08 by mrizakov          #+#    #+#             */
/*   Updated: 2024/02/26 17:00:31 by mrizakov         ###   ########.fr       */
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

        void    highFivesGuys(void);

    protected:
        string          _name;
};

#endif
