/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrizakov <mrizakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 19:01:08 by mrizakov          #+#    #+#             */
/*   Updated: 2024/02/26 18:38:02 by mrizakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef    ANIMAL_HPP
#define    ANIMAL_HPP

#include <iostream>
#include <string>
#include "Brain.hpp"

class Animal
{
    protected:
        std::string  _type;

        Animal(void);
        Animal(const Animal& other);
        virtual Animal& operator=(const Animal& other);
        
    public:
        
        virtual ~Animal(void);
        
        

        virtual void        makeSound(void) const;
        std::string         getType(void) const;
        // virtual void        giveIdeas(std::string thought, unsigned int i);
        // virtual std::string checkIdeas(unsigned int i);
        
        //virtual void        giveIdeas(std::string thought, unsigned int i);

};

#endif
