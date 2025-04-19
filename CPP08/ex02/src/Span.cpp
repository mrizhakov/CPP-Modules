/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrizakov <mrizakov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 01:08:36 by mrizakov          #+#    #+#             */
/*   Updated: 2025/04/19 13:40:27 by mrizakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : 
max_stored(0),
current_stored(0)
{};

Span::Span(unsigned int max_stored) : 
    max_stored(max_stored),
    current_stored(0)
{    
    
};

Span::~Span()
{};

Span::Span(const Span& other) :
    max_stored(other.max_stored)
{
    if (this->vec != other.vec)
    {
        this->current_stored = other.current_stored;
        std::vector<int> vec(other.vec);
    }
};

Span& Span::operator=(const Span & other)
{
    if (this != &other) {
        this->current_stored = other.current_stored;
        this->max_stored = other.max_stored;
        this->vec = other.vec;
    }
    return *this;        
};


void Span::addNumber(int number) {
    if (this->current_stored >= this->max_stored)
        throw std::out_of_range("Cannot add more elements - Span is full");
    this->vec.push_back(number);
    this->current_stored++;
    std::cout << "Added element of the span : " << number << " , number of elements in span : " << this->current_stored << std::endl;
};

unsigned int Span::shortestSpan() const {
    if (this->current_stored <= 1)
        throw std::exception();
    unsigned int smallest_offset = UINT_MAX;
    unsigned int current_offset;
    (void)current_offset;
    std::vector<int> vec_copy;
    vec_copy = vec;
    std::sort(vec_copy.begin(), vec_copy.end());

    for (std::vector<int>::const_iterator it = vec_copy.begin(); it != vec_copy.end(); it++)
    {
        *it < *(it-1) ? current_offset = *(it-1) - *it : current_offset = *it - *(it-1);
        if (current_offset < smallest_offset)
            smallest_offset = current_offset;
        if (smallest_offset <= 1)
            break;
    }
    return smallest_offset;
};

unsigned int Span::longestSpan() const {
    if (this->current_stored <= 1)
        throw std::exception();
    std::vector<int>::const_iterator min_it = std::min_element(vec.begin(), vec.end());
    std::vector<int>::const_iterator max_it = std::max_element(vec.begin(), vec.end());
    return *max_it - *min_it;
};

void        Span::addMultipleRandom(int number) {
    if (this->current_stored + number > this->max_stored)
        throw std::exception();
    std::vector<int> vec;
    this->vec.reserve(this->max_stored);
    srand(time(NULL));

    for (int i = 0; i < number; i++)
    {
        addNumber(rand());
    }
};
