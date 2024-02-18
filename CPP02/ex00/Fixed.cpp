/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrizakov <mrizakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 15:13:37 by mrizakov          #+#    #+#             */
/*   Updated: 2024/02/17 19:11:58 by mrizakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Fixed.hpp"


Fixed::Fixed(void) : _rawBits(0) {
    std::cout << "Default constructor called" << std::endl;
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
    std::cout << "getRawBits member function called" << std::endl;
    return (this->_rawBits);   
}
void Fixed::setRawBits(int const raw) {
    std::cout << "setRawBits member function called" << std::endl;
    this->_rawBits = raw;
}

const int Fixed::_n_fract_bits = 8;

