/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrizhakov <mrizhakov@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 19:01:08 by mrizakov          #+#    #+#             */
/*   Updated: 2024/03/02 17:51:12 by mrizhakov        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef    WRONGCAT_HPP
#define    WRONGCAT_HPP

#include <iostream>
#include <string>
#include "WrongAnimal.hpp"


class WrongCat: virtual public WrongAnimal
{
    protected:
        std::string  _type;
        

    public:
        WrongCat(void);
        ~WrongCat(void);
        WrongCat(const WrongCat& other);
        WrongCat& operator=(const WrongCat& other);

        void    makeNoise(void) const;
        void    makeSound(void) const;
        std::string getType(void) const;
};

#endif
