/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrizakov <mrizakov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 01:08:42 by mrizakov          #+#    #+#             */
/*   Updated: 2025/05/08 16:18:06 by mrizakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <stdexcept>
#include <fstream>

int main(int argc, char *argv[])
{
    BitcoinExchange btc_exchange;

    try
    {
        btc_exchange.run(argc, argv);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return (0);
}
