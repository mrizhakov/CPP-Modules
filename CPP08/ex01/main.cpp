/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrizakov <mrizakov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 12:04:31 by mrizakov          #+#    #+#             */
/*   Updated: 2025/04/14 19:21:24 by mrizakov         ###   ########.fr       */
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

    return 0;
}