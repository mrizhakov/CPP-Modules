/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrizakov <mrizakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 15:13:37 by mrizakov          #+#    #+#             */
/*   Updated: 2024/02/19 17:44:45 by mrizakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <limits.h>
#include "Fixed.hpp"



int main(void) {
    Fixed a;
    Fixed const b(Fixed(5.05f) * Fixed(2));
    std::cout << "a is " << a << std::endl;
    std::cout << "++a is " << ++a << std::endl;
    std::cout << "a is " << a << std::endl;
    std::cout << "a++ is " << a++ << std::endl;
    std::cout << "a is " << a << std::endl;
    
    std::cout << "b is " << b << std::endl;

    std::cout << "max is " << Fixed::max(a, b) << std::endl;
    std::cout << "min is " << Fixed::min(a, b) << std::endl;
    a = 21312.2525f;
    std::cout << "a is " << a << std::endl;
    std::cout << "b is " << b << std::endl;


    std::cout << "a * b is " << a * b << std::endl;
    std::cout << "a / b is " << a / b << std::endl;
    std::cout << "a + b is " << a + b << std::endl;
    std::cout << "a - b is " << a - b << std::endl;
    std::cout << "a > b is " << (a > b) << std::endl;
    std::cout << "a <= b is " << (a <= b) << std::endl;
    std::cout << "a < b is " << (a < b) << std::endl;
    std::cout << "a >= b is " << (a >= b) << std::endl;
    std::cout << "a != b is " << (a != b) << std::endl;

    return(0);
}

