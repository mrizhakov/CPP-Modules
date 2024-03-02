/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrizakov <mrizakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 19:01:08 by mrizakov          #+#    #+#             */
/*   Updated: 2024/02/26 18:38:02 by mrizakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef    WRONGANIMAL_HPP
#define    WRONGANIMAL_HPP

#include <iostream>
#include <string>

class WrongAnimal
{
    protected:
        std::string  _type;
        

    public:
        WrongAnimal(void);
        virtual ~WrongAnimal(void);
        WrongAnimal(const WrongAnimal& other);
        virtual WrongAnimal& operator=(const WrongAnimal& other);

        void                makeSound(void) const;
        virtual std::string getType(void) const;
};

#endif
