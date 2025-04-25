/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrizakov <mrizakov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 01:08:32 by mrizakov          #+#    #+#             */
/*   Updated: 2025/04/25 20:32:49 by mrizakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#pragma once

#include <iostream>


class ScalarConverter
{
    private:        
        ScalarConverter(void);
        ~ScalarConverter(void);
        ScalarConverter(const ScalarConverter& other);
        ScalarConverter& operator=(const ScalarConverter& other);

    public:
        static bool isChar(const std::string &input);
        static bool isInt(const std::string &input);
        static bool isFloat(const std::string &input);
        static bool isDouble(const std::string &input);
        static void specialCases(const std::string &input);

        static void convert(const std::string &input);
};

