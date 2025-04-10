/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Templates.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrizakov <mrizakov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 01:08:32 by mrizakov          #+#    #+#             */
/*   Updated: 2025/04/10 22:00:16 by mrizakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>


template <typename T>
T& min(T &a, T &b) {
    return (a >= b) ? b : a;
}

template <typename T>
T& max(T& a, T& b) {
    return (a <= b) ? b : a;
}

template <typename T>
void swap(T& a, T& b) {
    T& temp = a;
    a = b;
    b = temp;
}
