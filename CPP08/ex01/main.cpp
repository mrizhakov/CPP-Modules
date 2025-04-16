/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrizakov <mrizakov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 12:04:31 by mrizakov          #+#    #+#             */
/*   Updated: 2025/04/16 22:27:12 by mrizakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <iostream>
#include <ctime>
#include <Span.hpp>


int main(int, char**)
{
    Span span(5);
    srand(time(NULL));

    for (int i = 0; i < 5; i++)
    {
        unsigned int number = rand();
        span.addNumber(number);
        std::cout << "Elements of the span are: " << number << std::endl;

    }
    std::cout << "Longest span is " << span.longestSpan() << std::endl;
    std::cout << "Shortest span is " << span.shortestSpan() << std::endl;

    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    try {
    std::cout << sp.shortestSpan() << std::endl;
    } catch (...) {}
    try { 
    std::cout << sp.longestSpan() << std::endl;
    } catch (...) {}
    Span sp1 = Span(0);
    sp1.addNumber(6);

    return 0;
}