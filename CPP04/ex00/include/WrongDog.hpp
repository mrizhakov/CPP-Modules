/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongDog.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrizakov <mrizakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 19:01:08 by mrizakov          #+#    #+#             */
/*   Updated: 2024/03/02 18:36:30 by mrizakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef    WRONGDOG_HPP
#define    WRONGDOG_HPP

#include <iostream>
#include <string>
#include "WrongAnimal.hpp"


class WrongDog: virtual public WrongAnimal
{
    protected:
        std::string  _type;
        

    public:
        WrongDog(void);
        ~WrongDog(void);
        WrongDog(const WrongDog& other);
        WrongDog& operator=(const WrongDog& other);

        void        makeSound(void) const;
        std::string getType(void) const;
};

#endif
