/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrizakov <mrizakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 15:13:37 by mrizakov          #+#    #+#             */
/*   Updated: 2024/02/18 18:32:28 by mrizakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cmath>
#include <limits.h>

#include "Fixed.hpp"


Fixed::Fixed(void) : _rawBits(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int const n) {
    if ((n > INT_MAX / (1 << Fixed::_n_fract_bits))
        ||  (n < (INT_MIN / (1 << Fixed::_n_fract_bits))))
    {
            std::cout << "Warning: Out of range for current implementation of fixed point number, will overflow" << std::endl;
            std::cout << "try numbers between INT/MIN / 1 << 8 and INT/MAX / 1 << 8" << std::endl;
    }
    std::cout << "Int constructor called" << std::endl;
    this->_rawBits = (n << Fixed::_n_fract_bits);
}

Fixed::Fixed(float const floatN) {
    if (((floatN > (roundf(INT_MAX / (1 << Fixed::_n_fract_bits) -1 ))))
        ||  (floatN < (roundf(INT_MIN / (1 << Fixed::_n_fract_bits) + 1))))
    {
            std::cout << "Warning: Out of range for current implementation of fixed point number, will overflow" << std::endl;
            std::cout << "try numbers between INT/MIN / 1 << 8 and INT/MAX / 1 << 8" << std::endl;
    }
    std::cout << "Float constructor called" << std::endl;
    this->_rawBits = roundf(floatN * (1 << Fixed::_n_fract_bits));
}

float Fixed::toFloat(void) const {
    float n = (float)this->_rawBits / (float)(1 << Fixed::_n_fract_bits);
    return (n);
}

int Fixed::toInt(void) const {
    int n = this->_rawBits >> this->_n_fract_bits;
    return (n);
}


Fixed::~Fixed(void) {
    std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &fixed2) {
    this->setRawBits(fixed2.getRawBits());
    std::cout << "Copy assignment operator called" << std::endl;
    return (*this);
}

Fixed::Fixed(const Fixed &fixed) {
    std::cout << "Copy constructor called" << std::endl;
    this->setRawBits(fixed.getRawBits());
}

int Fixed::getRawBits(void) const {
    return (this->_rawBits);   
}
void Fixed::setRawBits(int const raw) {
    this->_rawBits = raw;
}

std::ostream &operator<<(std::ostream &stream, Fixed const &f) {
    stream << f.toFloat();
    return(stream);
}

const int Fixed::_n_fract_bits = 8;



