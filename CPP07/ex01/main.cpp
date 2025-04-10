/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrizakov <mrizakov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 12:04:31 by mrizakov          #+#    #+#             */
/*   Updated: 2025/04/10 23:13:27 by mrizakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <iostream>
#include <Iter.hpp>

void add_one(char& c)
{
    c++;
}

void add_one(int& c)
{
    c++;
}

int main(int, char**)
{
    std::string str = "hello";
    iter(&str[0], str.length(), add_one);
    
    std::cout << str << std::endl;

    int *arr = new int[2];
    
    arr[0] = 1;
    arr[1] = 3;

    iter(arr, 2, add_one);
    
    std::cout << arr[0] << arr[1] << std::endl;
    delete[] arr;
    return 0;
}