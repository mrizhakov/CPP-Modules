/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrizakov <mrizakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 19:01:08 by mrizakov          #+#    #+#             */
/*   Updated: 2024/02/26 18:38:02 by mrizakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef    DOG_HPP
#define    DOG_HPP

#include <iostream>
#include <string>
#include "Animal.hpp"


class Dog: virtual public Animal
{
    private:
        Brain *_animalBrain;
        
    public:
        Dog(void);
        ~Dog(void);
        Dog(const Dog& other);
        Dog& operator=(const Dog& other);

        void        makeSound(void) const;
        void        giveIdeas(std::string thought, unsigned int i);
        std::string checkIdeas(unsigned int i);
};

#endif
