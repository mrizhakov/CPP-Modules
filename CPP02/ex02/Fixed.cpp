/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrizakov <mrizakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 15:13:37 by mrizakov          #+#    #+#             */
/*   Updated: 2024/02/18 18:35:13 by mrizakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cmath>
#include <limits.h>

#include "Fixed.hpp"


Fixed::Fixed(void) : _rawBits(0) {
    //std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int const n) {
    if ((n > INT_MAX / (1 << Fixed::_n_fract_bits))
        ||  (n < (INT_MIN / (1 << Fixed::_n_fract_bits))))
    {
            std::cout << "Out of range for current implementation of fixed point number, will overflow" << std::endl;
            std::cout << "try numbers between INT/MIN / 1 << 8 and INT/MAX / 1 << 8" << std::endl;
    }
        //std::cout << "Int constructor called" << std::endl;
        this->_rawBits = (n << Fixed::_n_fract_bits);
}

Fixed::Fixed(float const floatN) {
    if (((floatN > (roundf(INT_MAX / (1 << Fixed::_n_fract_bits) -1 ))))
        ||  (floatN < (roundf(INT_MIN / (1 << Fixed::_n_fract_bits) + 1))))
    {
            std::cout << "Warning : out of range for current implementation of fixed point number, will overflow" << std::endl;
            std::cout << "try numbers between INT/MIN / 1 << 8 and INT/MAX / 1 << 8" << std::endl;
    }
    //std::cout << "Float constructor called" << std::endl;
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
    //std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &fixed2) {
    this->setRawBits(fixed2.getRawBits());
    //std::cout << "Copy assignment operator called" << std::endl;
    return (*this);
}

bool Fixed::operator>(const Fixed &fixed2) const {
    if (this->_rawBits > fixed2.getRawBits())
        return (true);
    return (false);
}

bool Fixed::operator<(const Fixed &fixed2) const {
    if (this->_rawBits < fixed2.getRawBits())
        return (true);
    return (false);
}

bool Fixed::operator>=(const Fixed &fixed2) const {
    if (this->_rawBits >= fixed2.getRawBits())
        return (true);
    return (false);
}

bool Fixed::operator<=(const Fixed &fixed2) const {
    if (this->_rawBits <= fixed2.getRawBits())
        return (true);
    return (false);
}

bool Fixed::operator==(const Fixed &fixed2) const {
    if (this->_rawBits == fixed2.getRawBits())
        return (true);
    return (false);
}

bool Fixed::operator!=(const Fixed &fixed2) const {
    if (this->_rawBits != fixed2.getRawBits())
        return (true);
    return (false);
}

Fixed Fixed::operator+(const Fixed &fixed2) const {
    Fixed result;
    result.setRawBits(this->_rawBits + fixed2.getRawBits());
    return (result);
}

Fixed Fixed::operator-(const Fixed &fixed2) const {
    Fixed result;
    result.setRawBits(this->_rawBits - fixed2.getRawBits());
    return (result);
}

Fixed Fixed::operator/(const Fixed &fixed2) const {
    Fixed result;
    result.setRawBits(this->_rawBits / fixed2.getRawBits());
    return (result);
}

Fixed Fixed::operator*(const Fixed &fixed2) const {
    Fixed result;
    result.setRawBits(this->_rawBits * fixed2.getRawBits());
    return (result);
}

// ++i post-increment
Fixed &Fixed::operator++(void) {
    this->_rawBits++;
    return (*this);
}

Fixed &Fixed::operator--(void) {
    this->_rawBits--;
    return (*this);
}

// i++ pre-increment
Fixed Fixed::operator++(int) {
    Fixed temp(*this);
    ++(*this);
    return (temp);
}

Fixed Fixed::operator--(int) {
    Fixed temp(*this);
    ++(*this);
    return (temp);
}

Fixed const &Fixed::max(Fixed const &fixed1, Fixed const &fixed2) {
    if (fixed1.getRawBits() >= fixed2.getRawBits())
        return (fixed1);
    else
        return (fixed2);
}

Fixed const &Fixed::min(Fixed const &fixed1, Fixed const &fixed2) {
    if (fixed1.getRawBits() <= fixed2.getRawBits())
        return (fixed1);
    else
        return (fixed2);
}

Fixed &Fixed::max(Fixed &fixed1, Fixed &fixed2) {
    if (fixed1.getRawBits() >= fixed2.getRawBits())
        return (fixed1);
    else
        return (fixed2);
}

Fixed &Fixed::min(Fixed &fixed1, Fixed &fixed2) {
    if (fixed1.getRawBits() <= fixed2.getRawBits())
        return (fixed1);
    else
        return (fixed2);
}


Fixed::Fixed(const Fixed &fixed) {
    //std::cout << "Copy constructor called" << std::endl;
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