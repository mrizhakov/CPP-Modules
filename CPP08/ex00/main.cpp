/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrizakov <mrizakov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 12:04:31 by mrizakov          #+#    #+#             */
/*   Updated: 2025/04/14 18:27:03 by mrizakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <iostream>
#include <easyfind.hpp>


int main(int, char**)
{
    std::vector<std::string> words;
    words.push_back("how");
    words.push_back("are");
    words.push_back("you");
    std::string word = "are";
    std::string found1 = easyfind(words, word);
    std::cout << found1 << std::endl;


    std::string str = "hello";
    char c = 'e';

    char found = easyfind(str, c);
    std::cout << found << std::endl;
    
    char e = 'x';

    char found2 = easyfind(str, e);
    std::cout << found2 << std::endl;
    
    return 0;
}