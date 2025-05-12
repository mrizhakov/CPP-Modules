/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrizakov <mrizakov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 01:08:36 by mrizakov          #+#    #+#             */
/*   Updated: 2025/05/08 16:12:40 by mrizakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <stdexcept>
#include <string>
#include <sstream>


PmergeMe::PmergeMe(void) {}

PmergeMe::~PmergeMe(void) {}

PmergeMe::PmergeMe(const PmergeMe &other)
{
   (void)other;
   *this = other;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
   (void)other;
   return *this;
}

void PmergeMe::runCalculator(int argc, char *argv[]) 
{
   checkArgs(argc, argv);
   // pushAndCalculate(argv[1]);
   // outputResult(stack);
   // printStack(stack);
}

void PmergeMe::checkArgs(int argc, char *argv[]) {
   if (argc == 1)
      throw std::runtime_error("Please provide arguments to be sorted in the format ./PmergeMe 1 2 3 4");
   for (int i = 1; i < argc; i++) {
   std::istringstream iss(argv[i]);
   int pmerge_int;
   if (iss >> pmerge_int && pmerge_int > 0)
   {
      pmerge_deque.push_back(pmerge_int);
   }
   else
      throw std::runtime_error("Please provide valid numeric positive arguments");
   }
}

// void PmergeMe::pushAndCalculate(char *argv) {
//    int left_var;
//    int right_var;
//    while (*argv != '\0')
//    {
//       if (isdigit(*argv))
//          stack.push(*argv - '0');
//       else if (*argv == '-' || *argv == '+' ||*argv == '/' ||*argv == '*')
//       {
//          if (stack.empty())
//             throw std::runtime_error("Incorrect input arguments, not enough numbers or too many operands");
//          else
//          {
//             right_var = stack.top();
//             stack.pop();  
//             left_var = stack.top();
//             stack.pop();          
//          }
//          if (*argv == '-')
//             left_var -= right_var;
//          if (*argv == '+')
//             left_var += right_var;
//          if (*argv == '*')
//             left_var *= right_var;
//          if (*argv == '/')
//             left_var /= right_var;
//          stack.push(left_var);
//       }
//       else if (*argv == ' ') {
//       }
//       else
//          throw std::runtime_error("Incorrect input arguments, please provide only digits or /*-+ operands");
//       argv++;
//    }
// }

// void PmergeMe::printStack(std::stack<int> stack) {
//    if (stack.empty())
//       std::cout << "Stack is empty!" << std::endl;
//    while (!stack.empty())
//    {
//       std::cout << stack.top() << " ";
//       stack.pop();
//    }
//    std::cout << std::endl;
// };

// void PmergeMe::outputResult(std::stack<int> stack) const {
//    if (stack.size() == 1)
//       std::cout << "Result: " << stack.top() << std::endl;
//    else 
//       throw std::runtime_error("Incorrect input, try again");
// };
