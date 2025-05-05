/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrizhakov <mrizhakov@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 01:08:42 by mrizakov          #+#    #+#             */
/*   Updated: 2025/04/29 17:48:07 by mrizhakov        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <stdexcept>
#include <fstream>

int main(int argc, char *argv[])
{
    BitcoinExchange btc_exchange = BitcoinExchange();

    try
    {
        btc_exchange.run(argc, argv);

        // btc_exchange.validateArgs(argc, argv, file);
    }
    catch (std::exception &e)
    {
        // file.close();
        std::cerr << e.what() << std::endl;
    }

    return (0);
}
