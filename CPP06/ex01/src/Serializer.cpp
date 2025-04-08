/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrizakov <mrizakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 00:09:35 by mrizakov          #+#    #+#             */
/*   Updated: 2025/04/09 00:40:07 by mrizakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer(void) {}

Serializer::~Serializer(void) {}

Serializer::Serializer(const Serializer& other)
{
   (void)other;
   *this = other;
}

Serializer&    Serializer::operator=(const Serializer& other)
{
   (void)other;
   return *this;
}

uintptr_t Serializer::serialize(Data* ptr) {
   return reinterpret_cast<uintptr_t>(ptr);
};

Data* Serializer::deserialize(uintptr_t raw) {
   return reinterpret_cast<Data*>(raw);
};