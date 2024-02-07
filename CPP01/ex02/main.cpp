/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrizakov <mrizakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 15:13:37 by mrizakov          #+#    #+#             */
/*   Updated: 2024/02/07 18:35:38 by mrizakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <limits>

int main(void)
{
    std::string str = "HI THIS IS BRAIN";
    std::string *stringPTR = &str;
    std::string &stringREF = str;

    std::cout << "Memory address of str is " << &str << std::endl;
    std::cout << "Memory address of stringPTR is " << &stringPTR << std::endl;
    std::cout << "Memory address of stringREF is " << &stringREF << std::endl;

    std::cout << "Value of str is " << str << std::endl;
    std::cout << "Value of str is " << *stringPTR << std::endl;
    std::cout << "Value of str is " << stringREF << std::endl;
    return(0);
}