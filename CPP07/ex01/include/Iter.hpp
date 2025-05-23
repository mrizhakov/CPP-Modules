/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrizakov <mrizakov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 01:08:32 by mrizakov          #+#    #+#             */
/*   Updated: 2025/04/19 17:39:05 by mrizakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

template <typename T>
void iter(T* array, int length, void (*function)(T&)) {
    for (int i = 0; i < length; i++) {
        function(array[i]);
    }
}
// Overload for const
template <typename T>
void iter(T* array, int length, void (*function)(const T&)) {
    for (int i = 0; i < length; i++) {
        function(array[i]);
    }
}

template<typename T>
void add_one(T& c)
{
    c++;
}

