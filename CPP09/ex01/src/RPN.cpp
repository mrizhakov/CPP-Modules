/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrizakov <mrizakov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 01:08:36 by mrizakov          #+#    #+#             */
/*   Updated: 2025/05/08 16:12:40 by mrizakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <stdexcept>
#include <cctype>
#include <iostream>


RPN::RPN(void) {}

RPN::~RPN(void) {}

RPN::RPN(const RPN &other)
{
   (void)other;
   *this = other;
}

RPN &RPN::operator=(const RPN &other)
{
   (void)other;
   return *this;
}

void RPN::runCalculator(int argc, char *argv[]) 
{
   checkArgs(argc);
   tokenizeInputLine(argv[1]);
   outputResult(stack);
   // printStack(stack);
}

void RPN::checkArgs(int argc) const {
   if (argc != 2)
      throw std::runtime_error("Incorrect number of arguments");
}

void RPN::tokenizeInputLine(char *argv) {
   int left_var;
   int right_var;
   while (*argv != '\0')
   {
      if (isdigit(*argv))
      {
         stack.push(*argv - '0');
         // std::cerr << "Pushed a digit: " << *argv << std::endl;
         // printStack(stack);
      }
      else if (*argv == '-' || *argv == '+' ||*argv == '/' ||*argv == '*')
      {
         // std::cerr << "Found an operand: " << *argv << std::endl;
         if (stack.empty())
            throw std::runtime_error("Incorrect input arguments, not enough numbers or too many operands");
         if (!stack.empty())
         {
            right_var = stack.top();
            // std::cerr << "Right_var is : " << right_var << std::endl;
            stack.pop();         
         }

         if (!stack.empty())
         {
            left_var = stack.top();
            // std::cerr << "left_var is : " << left_var << std::endl;
            stack.pop();         
         }
         if (*argv == '-')
            left_var -= right_var;
         if (*argv == '+')
            left_var += right_var;
         if (*argv == '*')
            left_var *= right_var;
         if (*argv == '/')
            left_var /= right_var;
         stack.push(left_var);
         // std::cerr << "Operation result is , pushed result back to stack: " << left_var << std::endl;
         // printStack(stack);

      }
      else if (*argv == ' ') {
      }
      else
      {
         throw std::runtime_error("Incorrect input arguments, please provide only digits or /*-+ operands");
      }
      argv++;
   }
}

void RPN::printStack(std::stack<int> stack) {
   if (stack.empty())
      std::cout << "Stack is empty!" << std::endl;
   while (!stack.empty())
   {
      std::cout << stack.top() << " ";
      stack.pop();
   }
   std::cout << std::endl;
};

void RPN::outputResult(std::stack<int> stack) const {
   if (stack.size() == 1)
      std::cout << "Result: " << stack.top() << std::endl;
   else 
      throw std::runtime_error("Incorrect input, try again");
};
