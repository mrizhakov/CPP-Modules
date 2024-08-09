/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrizakov <mrizakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 19:01:08 by mrizakov          #+#    #+#             */
/*   Updated: 2024/02/26 18:38:02 by mrizakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef    AANIMAL_HPP
#define    AANIMAL_HPP

#include <iostream>
#include <string>
#include "Brain.hpp"

class AAnimal
{
    protected:
        std::string  _type;

        
    public:
        
        virtual ~AAnimal(void);
        AAnimal(void);
        AAnimal(const AAnimal& other);
        virtual AAnimal& operator=(const AAnimal& other);
        
        virtual void        makeSound(void) const = 0;
        std::string         getType(void) const;
};

#endif
