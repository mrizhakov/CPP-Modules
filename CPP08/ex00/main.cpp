/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrizakov <mrizakov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 12:04:31 by mrizakov          #+#    #+#             */
/*   Updated: 2025/04/24 16:30:15 by mrizakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <iostream>
#include <easyfind.hpp>


int main(int, char**)
{
    int arr[] = {1, 2, 3, 4, 5};
    std::vector<int> numbers_arr(arr, arr + 5);
    
    int found = easyfind(numbers_arr, 3);
    std::cout << found << std::endl;

    return 0;
}