/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrizakov <mrizakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 19:01:08 by mrizakov          #+#    #+#             */
/*   Updated: 2024/02/26 18:38:02 by mrizakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef    CAT_HPP
#define    CAT_HPP

#include <iostream>
#include <string>
#include "Animal.hpp"


class Cat: virtual public Animal
{
    public:
        Cat(void);
        ~Cat(void);
        Cat(const Cat& other);
        Cat& operator=(const Cat& other);

        void        makeSound(void) const;
};

#endif
