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
#include <iostream>
#include <cstdio>
#include <algorithm>



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

    // Step 1: Pair elements into smalls and larges
   std::vector<unsigned int> smalls, larges;
   int leftover = -1;
   for (size_t i = 0; i + 1 < pmerge_deque.size(); i += 2) {
      int a = pmerge_deque[i];
      int b = pmerge_deque[i + 1];
      if (a < b) {
         smalls.push_back(a);
         larges.push_back(b);
      } else {
         smalls.push_back(b);
         larges.push_back(a);
      }
   }
   if (pmerge_deque.size() % 2 != 0) {
     leftover = pmerge_deque.back();
   }

   // Step 2: Sort larges to create the main chain
   std::sort(larges.begin(), larges.end());
   std::deque<unsigned int> main_chain(larges.begin(), larges.end());

   // Step 3: Insert smalls based on Jacobsthal order
   std::vector<unsigned int> insertion_order = getJacobsthalIndices(smalls.size());
   for (size_t i = 0; i < insertion_order.size(); ++i) {
      int index = insertion_order[i];
      if (index < (int)smalls.size()) {
         binaryInsert(main_chain, smalls[index]);
      }
   }

    // Step 4: Insert leftover if exists
   if (leftover != -1) {
      binaryInsert(main_chain, leftover);
   }



   printDeque(pmerge_deque);
   printDeque(main_chain);

}

void PmergeMe::checkArgs(int argc, char *argv[]) {
   if (argc == 1)
      throw std::runtime_error("Please provide arguments to be sorted in the format ./PmergeMe 1 2 3 4");
   for (int i = 1; i < argc; i++) {
   std::istringstream iss(argv[i]);
   int pmerge_int;
   if (iss >> pmerge_int && iss.peek() == EOF && pmerge_int > 0)
   {
      pmerge_deque.push_back(pmerge_int);
   }
   else
      throw std::runtime_error("Please provide valid numeric positive arguments");
   }
   // char leftover;
   // if (iss >> pmerge_int && !(iss >> leftover) && pmerge_int > 0)
   // {
   //    pmerge_deque.push_back(pmerge_int);
   // }
   // else
   //    throw std::runtime_error("Please provide valid numeric positive arguments");
   // }
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

void PmergeMe::printDeque(std::deque<unsigned int> pmerge_deque) {
   if (pmerge_deque.empty())
      std::cout << "pmerge_deque is empty!" << std::endl;
   while (!pmerge_deque.empty())
   {
      std::cout << pmerge_deque.front() << " ";
      pmerge_deque.pop_front();
   }
   std::cout << std::endl;
};

// void PmergeMe::outputResult(std::stack<int> stack) const {
//    if (stack.size() == 1)
//       std::cout << "Result: " << stack.top() << std::endl;
//    else 
//       throw std::runtime_error("Incorrect input, try again");
// };

std::vector<unsigned int> PmergeMe::getJacobsthalIndices(unsigned int n) {
    std::vector<unsigned int> indices;
    unsigned int j0 = 0, j1 = 1;
    while (j1 < n) {
        if (std::find(indices.begin(), indices.end(), j1) == indices.end())
            indices.push_back(j1);
        int j2 = j1 + 2 * j0;
        j0 = j1;
        j1 = j2;
    }
    // Fill in remaining indices not covered
    for (unsigned int i = 0; i < n; ++i) {
        if (std::find(indices.begin(), indices.end(), i) == indices.end())
            indices.push_back(i);
    }
    return indices;
}

void PmergeMe::binaryInsert(std::deque<unsigned int>& chain, unsigned int value) {
    std::deque<unsigned int>::iterator pos = std::lower_bound(chain.begin(), chain.end(), value);
    chain.insert(pos, value);
}