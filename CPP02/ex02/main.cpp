/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrizakov <mrizakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 15:13:37 by mrizakov          #+#    #+#             */
/*   Updated: 2024/02/18 18:26:27 by mrizakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <limits.h>
#include "Fixed.hpp"



int main(void)
{
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





    
    // Fixed const b(10);
    // Fixed const c(42.42f);
    // Fixed const d(b);

    // a = Fixed( 1234.4321f );
    
    // // //a = Fixed(8388605.29609f);
    // // a = Fixed((INT_MIN/256));
    // a++;
    // a++;


    


    // std::cout << "a is " << a << std::endl;
    // std::cout << "b is " << b << std::endl;
    // std::cout << "c is " << c << std::endl;
    // std::cout << "d is " << d << std::endl;

    // std::cout << "a is " << a.toInt() << " as integer" << std::endl;
    // std::cout << "b is " << b.toInt() << " as integer" << std::endl;
    // std::cout << "c is " << c.toInt() << " as integer" << std::endl;
    // std::cout << "d is " << d.toInt() << " as integer" << std::endl;
    
    
    return(0);
}

