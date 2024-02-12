/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrizakov <mrizakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 15:13:31 by mrizakov          #+#    #+#             */
/*   Updated: 2024/02/12 15:39:28 by mrizakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP


#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <limits>

class Harl {
    
    public:
    Harl(void);
    ~Harl(void);
    void complain(std::string level);

    private:
    void debug(void);
    void info(void);
    void warning(void);
    void error(void);
    struct _log
    {
        std::string level;
        void (Harl::*function)(void);
    };
    struct _log log[4];
};


#endif // HARL_HPP