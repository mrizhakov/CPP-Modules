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
bool ScalarConverter::isDouble(const std::string &input) 
{
   errno = 0;
   char *endptr = NULL;
   strtod(input.c_str(), &endptr);
   if (endptr == input.c_str() || *endptr != '\0' || errno == ERANGE)
   {
      return false;
   }
   return true;
}

bool ScalarConverter::isFloat(const std::string &input) 
{
   if (input.empty())
   {
      return false;
   }
   
   char last_char = input[input.size() - 1];
   if (last_char != 'f' && last_char != 'F')
   {
      return false;
   }
   
   std::string numPart = input.substr(0, input.size() - 1);
   
   if (!isDouble(numPart))
   {
      return false;
   }
   
   errno = 0;
   char *endptr = NULL;
   double result = strtod(numPart.c_str(), &endptr);

   if (result > FLT_MAX || result < -FLT_MAX)
   {
      return false;
   }
   
   return true;  
}

bool ScalarConverter::isInt(const std::string &input)
{
   errno = 0;
   char *endptr = NULL;
   strtol(input.c_str(), &endptr, 10);
   if (endptr == input.c_str() || *endptr != '\0' || errno == ERANGE)
   {
      return false;
   }
   return true;
}

bool ScalarConverter::isChar(const std::string &input)
{
   if (!input.empty() && (input.size() == 1) && isprint(input[0]) && !isdigit(input[0]))
   {
      std::cerr << "error here" << std::endl;
      return true;
      //empty string, no conversion possible
   }
   return false;
   
}

void ScalarConverter::specialCases(const std::string &input) {
   std::cout << "Char: impossible" << std::endl;
   std::cout << "Int: impossible" << std::endl;
   if (input == "nan" || input == "nanf") {
        std::cout << "Float: nanf" << std::endl;
        std::cout << "Double: nan" << std::endl;
        return; 
   }

   if (input == "+inf" || input == "+inff" || input == "inf" || input == "inff") {
        std::cout << "Float: inff" << std::endl;  
        std::cout << "Double: inf" << std::endl;
        return;
   }

   if (input == "-inf" || input == "-inff") {
        std::cout << "Float: -inff" << std::endl;
        std::cout << "Double: -inf" << std::endl;
        return;
   }

   if (input == "-nanf" || input == "-nan" || input == "+nanf" || input == "+nan") {
        std::cout << "Float: impossible" << std::endl;
        std::cout << "Double: impossible" << std::endl;
        return;
    }
}

void ScalarConverter::convert(const std::string &input)
{
   // Empty string case
   if (input.empty())
   {
      std::cout << "Char: impossible" << std::endl;
      std::cout << "Int: impossible" << std::endl;
      std::cout << "Float: impossible" << std::endl;
      std::cout << "Double: impossible" << std::endl;
      return;
   }
   // Special cases
   if (input == "nan" || input == "nanf" || input == "+inf" || input == "+inff" 
      || input == "inf" || input == "inff" ||input == "-inf" || input == "-inff"
      || input == "-nan" || input == "-nanf" || input == "+nan" || input == "+nanf") 
   {
      specialCases(input);
      return;
   }

   // Single character case
   if (isChar(input))
   {
      char c = input[0];
      if (isprint(c)) {
         std::cout << "Char: \"" << static_cast<char>(c) << "\"" <<std::endl;
      }
      else {
         std::cout << "Char: non-displayable" << std::endl; 
      }
      std::cout << "Int: " << static_cast<int>(c) << std::endl;
      std::cout << "Float: " << static_cast<float>(c) << std::endl;
      std::cout << "Double: " << static_cast<double>(c) << std::endl;
      return;
   }


   double value;
   // All numbers will be converted to doubles or floats

   if (isFloat(input)) {
      // Numeric part, withoug the trailing f/F
      std::string numPart = input.substr(0, input.size() - 1);
      value = strtod(numPart.c_str(), NULL);
   } else if (isDouble(input) || isInt(input)) {
      value = strtod(input.c_str(), NULL);
   } else {
      std::cout << "Char: impossible" << std::endl;
      std::cout << "Int: impossible" << std::endl;
      std::cout << "Float: impossible" << std::endl;
      std::cout << "Double: impossible" << std::endl;
      return;
   }

   if (value >= 0 && value <= 127 && isprint(static_cast<int>(value))) {
      std::cout << "Char: \"" << static_cast<char>(value) << "\"" <<std::endl;
   } else {
      std::cout << "Char: non-displayable" << std::endl; 
   }

   if (value <= INT_MAX && value >= INT_MIN) {
      std::cout << "Int: " << static_cast<int>(value) << std::endl;
   } else {
      std::cout << "Int: impossible" << std::endl;
   }

   if (value <= FLT_MAX && value >= -FLT_MAX) { 
      if (value == static_cast<int>(value)) {
         std::cout << "Float: " << static_cast<float>(value) << ".0f" << std::endl;
      } else {
         std::cout << "Float: " << static_cast<float>(value) << "f" << std::endl;
      }
   } else {
      std::cout << "Float: impossible" << std::endl;
   }

   if (value == static_cast<int>(value)) {
      std::cout << "Double: " << value << ".0" << std::endl;
   } else {
      std::cout << "Double: " << value << std::endl;
   }
}