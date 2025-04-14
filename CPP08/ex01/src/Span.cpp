/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrizakov <mrizakov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 01:08:36 by mrizakov          #+#    #+#             */
/*   Updated: 2025/04/14 19:23:35 by mrizakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

// Span::Span() {
    
// };

Span::Span(unsigned int max_stored) : 
    max_stored(max_stored),
    current_stored(0)
{    
    
};

Span::~Span() {};
// Span(const Span& other);
// Span& operator=(const Span & other);


void Span::addNumber(int number) {
    if (this->current_stored >= this->max_stored)
        throw std::exception();
    this->vec.push_back(number);
};

unsigned int Span::shortestSpan() const {
    std:vector<int> vec_copy;
    vec_copy.sort();
    
    
    
};

unsigned int Span::longestSpan() const {
    std::vector<int>::const_iterator min_it = std::min_element(vec.begin(), vec.end());
    std::vector<int>::const_iterator max_it = std::max_element(vec.begin(), vec.end());
    return *max_it - *min_it;
};
