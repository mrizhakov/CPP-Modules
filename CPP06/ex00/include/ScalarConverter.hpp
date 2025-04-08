/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrizakov <mrizakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 19:01:08 by mrizakov          #+#    #+#             */
/*   Updated: 2024/02/26 18:38:02 by mrizakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <typeinfo>
#include <cstdlib>
#include <cfloat>
#include <cerrno>
#include <cctype>
#include <climits>

// #include <stdexcept>
// #include <iostream>
// #include <cstdlib>
// #include <cctype>



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

        static void    convert(const std::string &input);
};

