/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrizakov <mrizakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 19:01:08 by mrizakov          #+#    #+#             */
/*   Updated: 2024/02/26 18:38:02 by mrizakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef    BRAIN_HPP
#define    BRAIN_HPP

#include <iostream>
#include <string>

class Brain
{
    public:
        Brain(void);
        virtual ~Brain(void);
        Brain(const Brain& other);
        virtual Brain& operator=(Brain& other);
        
        void giveIdeas(std::string though);

        std::string _ideas[100];
};

#endif
