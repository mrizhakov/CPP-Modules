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

bool ScalarConverter::isInt(const std::string &input) {
   std::string::const_iterator it;
   if (input.empty())
   
   for (it = input.begin(); it != input.end(); ++it)
   {
      if (!std::isdigit(*it))
      {
         std::cerr << "Not a digit" << std::endl;

         return false;
      }
      std::cout << *it << std::endl;

   }
   return true;
}

// bool ScalarConverter::isPrintableChar(const std::string &input)
// {
//    char c;
//    int 
//    if (input)
// }

void ScalarConverter::convert(const std::string &input)
{
   (void)input;
   if (input.empty())
   {
      //empty string, no conversion possible
   }   
   char *endptr_strtod;
   char *endptr_strtof;

   double double_value = strtod(input.c_str(), &endptr_strtod);
   float float_value = strtof(input.c_str(), &endptr_strtof);
   (void)float_value;
   (void)double_value;
   if (*endptr_strtod == '\0' || *endptr_strtof == '\0')
   {
      char convChar = static_cast<char>(double_value);
      int convInt = static_cast<int>(double_value);
      float convFloat = static_cast<float>(double_value);
      double convDouble = static_cast<double>(double_value);
      (void)convInt;
      (void)convFloat;
      (void)convDouble;


      std::cout << "Conversion succesfull " << std::endl;
      if (isprint(convChar)) {
         std::cout << "Char: " << convChar << std::endl;
      }
      else {
         std::cout << "Char: non-displayable" << std::endl; 
      }
      std::cout << "Int: " << static_cast<int>(double_value) << std::endl;
      std::cout << "Float: " << static_cast<float>(double_value) <<  std::endl;
      std::cout << "Double: " << static_cast<double>(double_value) <<  std::endl;
   }
   else
   {
      std::cout << "Char: impossible" << std::endl;
      std::cout << "Int: impossible" << std::endl;
      std::cout << "Float: impossible" << std::endl;
      std::cout << "Double: impossible" << std::endl;
   }
   




   // if (*endptr != '\0')
   // {
   //    std::cout << "Char: " << convChar << std::endl;
   //    std::cout << "Int: " << static_cast<int>(convChar[0]) << std::endl;
   //    std::cout << "Float: " << static_cast<float>(convChar[0]) << ".0f" << std::endl;
   //    std::cout << "Double: " << static_cast<double>(convChar[0]) << ".0" << std::endl;
   //    // could not perform conversion of string to double
   // }
   // if (input == "nan")
   
      


   // isInt(input);

   // if (typeid())

   // std::string convChar;
   // int         convInt;
   // float       convFloat;
   // double      convDouble;
   // (void)convDouble;
   // (void)convInt;
   // (void)convFloat;

   // if (input.empty())
   // {
   //    std::cout << "Input is empty." << std::endl;
   //    return ;
   // }
   // if (input.length() >= 1 && std::isprint(input[0]) && !std::isdigit(input[0]))
   // {
   //    convChar = input[0];  
   //    std::cout << "Char: " << convChar << std::endl;
   //    std::cout << "Int: " << static_cast<int>(convChar[0]) << std::endl;
   //    std::cout << "Float: " << static_cast<float>(convChar[0]) << ".0f" << std::endl;
   //    std::cout << "Double: " << static_cast<double>(convChar[0]) << ".0" << std::endl;
   //    return;
   // }
   // if (input.length() >= 1 && std::isprint(input[0]) && !std::isdigit(input[0]))
   // {
   //    convChar = input[0];  
   //    std::cout << "Char: " << convChar << std::endl;
   //    std::cout << "Int: " << static_cast<int>(convChar[0]) << std::endl;
   //    std::cout << "Float: " << static_cast<float>(convChar[0]) << ".0f" << std::endl;
   //    std::cout << "Double: " << static_cast<double>(convChar[0]) << ".0" << std::endl;
   //    return;
   // }







}


// std::ostream& operator<<(std::ostream& os, const ScalarConverter& b) {
//    os << "Bureacrat: " << b.getName() << ", Grade: " << b.getGrade();
//    return os;
// }
