/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrizakov <mrizakov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 01:08:32 by mrizakov          #+#    #+#             */
/*   Updated: 2025/04/14 19:13:01 by mrizakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include <exception>
#include <algorithm>
#include <vector>
#include <iostream>

class Span {
    private:
        const unsigned int max_stored;
        unsigned int current_stored;
        std::vector<int> vec;
        Span();

        
    public:
        Span(unsigned int max_stored);
        ~Span();
        Span(const Span& other);
        Span& operator=(const Span & other);
        
        void            addNumber(int number);
        unsigned int    shortestSpan() const;
        unsigned int    longestSpan() const;
    
};


