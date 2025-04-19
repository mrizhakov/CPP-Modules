/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrizakov <mrizakov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 00:07:00 by mrizakov          #+#    #+#             */
/*   Updated: 2025/04/19 17:59:28 by mrizakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <Array.hpp>
#include <stdlib.h>
#include <ctime>
#include <stdio.h>
#include <sstream>



#define MAX_VAL 750
int main(int, char**)
{
    Array<int> numbers0(0);
    Array<int> numbers1(1);
    Array<int> numbers5(5);

    // Array<const int> numbers5(5);

    srand(time(NULL));
    for (int i = 0; i < 5; i++)
    {
        numbers5[i] = rand();
        std::cout << "Added value: " << numbers5[i] << std::endl;

    }

    try
    {
        numbers5[3] = 0;
        std::cout << "Trying to write to value numbers5[3]: " << numbers5[3] << std::endl;

    }
    catch(const std::exception& e)
    {

        std::cerr << e.what() << '\n';
    }

    Array<std::string> words5(5);
    for (int i = 0; i < 5; i++)
    {
        std::stringstream ss;
        ss << "Different strings " << rand();
        words5[i] = ss.str();
        std::cout << "Added value: " << words5[i] << std::endl;

    }
    

    

    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;

    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            return 1;
        }
    }
    // try
    // {
    //     numbers[-2] = 0;
    // }
    // catch(const std::exception& e)
    // {

    //     std::cerr << e.what() << '\n';
    // }
    // try
    // {
    //     numbers[MAX_VAL] = 0;
    // }
    // catch(const std::exception& e)
    // {

    //     std::cerr << e.what() << '\n';
    // }

    // for (int i = 0; i < MAX_VAL; i++)
    // {
        

    //     numbers[i] = rand();
    // }
    
    delete [] mirror;//
    return 0;
}