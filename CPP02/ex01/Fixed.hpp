/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrizakov <mrizakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 15:13:31 by mrizakov          #+#    #+#             */
/*   Updated: 2024/02/17 19:12:24 by mrizakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <cmath>
#include <iostream>
#include <limits>

class Fixed {
    
    public:
    Fixed(void);
    Fixed(int const n);
    Fixed(float const n);
    float toFloat(void) const;
    int toInt(void) const;


    Fixed(const Fixed &fixed);
    Fixed &operator=(const Fixed &fixed2);
    ~Fixed(void);
    int getRawBits(void) const;
    void setRawBits(int const raw);
    
    private:
    int _rawBits;
    static const int _n_fract_bits;
};

std::ostream &operator<<(std::ostream &stream, Fixed const &f);


#endif // FIXED_HPP