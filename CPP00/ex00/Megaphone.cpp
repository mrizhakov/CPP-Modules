/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrizhakov <mrizhakov@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 17:37:25 by mrizhakov         #+#    #+#             */
/*   Updated: 2024/01/30 23:14:34 by mrizhakov        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main(int argc, char *argv[])
{
    int wc;
    std::string::iterator i;
    std::string output;
    std::string output_uppercased; 
      
    wc = 1;
    if (argc == 1)
    {
        std::cout <<  "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return (0);
    }
    while(argv[wc])
    {
        output.append(argv[wc]);
        if (argv[wc+1])
            output.append(" ");
        wc++;
    }
    i = output.begin();
    while (i != output.end())
    {
        output_uppercased += std::toupper(*i);
        i++;
    }
    std::cout <<  output_uppercased << std::endl;
    return (0);
}