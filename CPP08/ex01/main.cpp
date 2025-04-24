/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrizakov <mrizakov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 12:04:31 by mrizakov          #+#    #+#             */
/*   Updated: 2025/04/23 23:41:40 by mrizakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <iostream>
#include <ctime>
#include <Span.hpp>


int main(int, char**)
{
    Span span(100000);
    srand(time(NULL));

    for (int i = 0; i < 100000; i++)
    {
        unsigned int number = rand();
        span.addNumber(number);
        std::cout << "Elements of the span are: " << number << std::endl;

    }
    std::cout << "Longest span is " << span.longestSpan() << std::endl;
    std::cout << "Shortest span is " << span.shortestSpan() << std::endl;

    Span span1(999);
    span1.addMultipleRandom(999);
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
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    
    try { 
        std::cout << sp.longestSpan() << std::endl;
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    
    Span sp1 = Span(0);
    try {
        sp1.addNumber(6);
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    int arr[] = {1, 2, 3, 4, 5};
    std::vector<int> numbers_arr(arr, arr + 5);
    Span sp2 = Span(10);
    // Span sp(10);
    sp2.addRange(numbers_arr.begin(), numbers_arr.end());

    return 0;
}