/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrizakov <mrizakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 19:01:04 by mrizakov          #+#    #+#             */
/*   Updated: 2024/02/28 17:48:59 by mrizakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void) {}

ScalarConverter::~ScalarConverter(void) {}

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
   (void)other;
   *this = other;
}

ScalarConverter&    ScalarConverter::operator=(const ScalarConverter& other)
{
   (void)other;
   return *this;
}

void ScalarConverter::convert(const std::string &input)
{
   std::string convChar;
   int         convInt;
   float       convFloat;
   double      convDouble;
   (void)convDouble;
   (void)convInt;
   (void)convFloat;

   if (input.empty())
   {
      std::cout << "Input is empty." << std::endl;
      return ;
   }
   if (input.length() == 1 && std::isprint(input[0]) && !std::isdigit(input[0]))
   {
      convChar = input[0];  
      std::cout << "Char: " << convChar << std::endl;
      std::cout << "Int: " << static_cast<int>(convChar[0]) << std::endl;
      std::cout << "Float: " << static_cast<float>(convChar[0]) << ".0f" << std::endl;
      std::cout << "Double: " << static_cast<double>(convChar[0]) << ".0" << std::endl;
      return;
   }
   if (input.length()  1 && std::isprint(input[0]) && !std::isdigit(input[0]))
   {
      convChar = input[0];  
      std::cout << "Char: " << convChar << std::endl;
      std::cout << "Int: " << static_cast<int>(convChar[0]) << std::endl;
      std::cout << "Float: " << static_cast<float>(convChar[0]) << ".0f" << std::endl;
      std::cout << "Double: " << static_cast<double>(convChar[0]) << ".0" << std::endl;
      return;
   }







}


// std::ostream& operator<<(std::ostream& os, const ScalarConverter& b) {
//    os << "Bureacrat: " << b.getName() << ", Grade: " << b.getGrade();
//    return os;
// }
