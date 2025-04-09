/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrizakov <mrizakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 01:07:37 by mrizakov          #+#    #+#             */
/*   Updated: 2025/04/09 01:07:37 by mrizakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

\
#pragma once

#include <stdint.h>
#include <iostream>
#include <string>

struct Data {
    std::string some_data;
};

class Serializer
{
    private:        
        Serializer(void);
        ~Serializer(void);
        Serializer(const Serializer& other);
        Serializer& operator=(const Serializer& other);
        
    public:
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};

