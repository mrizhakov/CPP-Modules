/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrizakov <mrizakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 15:13:31 by mrizakov          #+#    #+#             */
/*   Updated: 2024/02/18 18:28:59 by mrizakov         ###   ########.fr       */
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
    ~Fixed(void);
    float toFloat(void) const;
    int toInt(void) const;


    Fixed(const Fixed &fixed);
    Fixed &operator=(const Fixed &fixed2);
    bool operator>(const Fixed &fixed2) const;
    bool operator<(const Fixed &fixed2) const;
    bool operator>=(const Fixed &fixed2) const;
    bool operator<=(const Fixed &fixed2) const;
    bool operator==(const Fixed &fixed2) const;
    bool operator!=(const Fixed &fixed2) const;

    Fixed operator+(const Fixed &fixed2) const;
    Fixed operator-(const Fixed &fixed2) const;
    Fixed operator/(const Fixed &fixed2) const;
    Fixed operator*(const Fixed &fixed2) const;

    Fixed &operator++(void); //++i
    Fixed &operator--(void);
    Fixed operator++(int); //i++
    Fixed operator--(int);
    static Fixed const &max(Fixed const &fixed1, Fixed const &fixed2);
    static Fixed const &min(Fixed const &fixed1, Fixed const &fixed2);
    static Fixed &max(Fixed &fixed1, Fixed &fixed2);
    static Fixed &min(Fixed &fixed1, Fixed &fixed2);


    int getRawBits(void) const;
    void setRawBits(int const raw);
    
    private:
    int _rawBits;
    static const int _n_fract_bits;
};

std::ostream &operator<<(std::ostream &stream, Fixed const &f);


#endif // FIXED_HPP