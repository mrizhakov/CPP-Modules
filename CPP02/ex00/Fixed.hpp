/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrizakov <mrizakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 15:13:31 by mrizakov          #+#    #+#             */
/*   Updated: 2024/02/17 19:10:44 by mrizakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP


#include <iostream>
#include <limits>

class Fixed {
    
    public:
    Fixed(void);
    Fixed(const Fixed &fixed);
    Fixed &operator=(const Fixed &fixed2);
    ~Fixed(void);
    int getRawBits(void) const;
    void setRawBits(int const raw);
    
    private:
    int _rawBits;
    static const int _n_fract_bits;
};

#endif // FIXED_HPP