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

void PmergeMe::runMergeInsertSort(int argc, char *argv[]) 
{
    checkArgs(argc, argv);
    std::cout << "Before: ";
    printDeque(pmerge_deque);
    pmerge_vector.assign(pmerge_deque.begin(), pmerge_deque.end());
    pmerge_vector.reserve(pmerge_vector.size());


    clock_t c_start_deque = clock();
    std::deque<unsigned int> sorted_result_deque = mergeInsertSortRecursiveDeque(pmerge_deque);
    clock_t c_end_deque = clock();
    double cpu_time_deque = double(c_end_deque - c_start_deque) / CLOCKS_PER_SEC * 1000000;

    clock_t c_start_vector = clock();
    std::vector<unsigned int> sorted_result_vector = mergeInsertSortRecursiveVector(pmerge_vector);
    clock_t c_end_vector = clock();
    double cpu_time_vector = double(c_end_vector - c_start_vector) / CLOCKS_PER_SEC * 1000000;


    std::cout << "After: ";
    printDeque(sorted_result_deque);
    printVector(sorted_result_vector);

    std::cout << "Time to process a range of " << sorted_result_deque.size() << " elements with std::deque : " << cpu_time_deque << " us" << std::endl;
    std::cout << "Time to process a range of " << sorted_result_vector.size() << " elements with std::vector : " << cpu_time_vector << " us" << std::endl;
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

void PmergeMe::printVector(std::vector<unsigned int> pmerge_deque) {
   if (pmerge_deque.empty())
      std::cout << "pmerge_deque is empty!" << std::endl;
   while (!pmerge_deque.empty())
   {
      std::cout << pmerge_deque.front() << " ";
      pmerge_deque.erase(pmerge_deque.begin());
   }
   std::cout << std::endl;
};


std::vector<unsigned int> PmergeMe::getJacobsthalIndexes(unsigned int n) {
    std::vector<unsigned int> indexes;
    unsigned int j0 = 0;
    unsigned int j1 = 1;
    while (j1 < n) {
        if (std::find(indexes.begin(), indexes.end(), j1) == indexes.end())
            indexes.push_back(j1);
        int j2 = j1 + 2 * j0;
        j0 = j1;
        j1 = j2;
    }
    // Fill in remaining indices not covered
    for (unsigned int i = 0; i < n; ++i) {
        if (std::find(indexes.begin(), indexes.end(), i) == indexes.end())
            indexes.push_back(i);
    }
    return indexes;
}

void PmergeMe::binaryInsertDeque(std::deque<unsigned int>& chain, unsigned int value) {
    std::deque<unsigned int>::iterator pos = std::lower_bound(chain.begin(), chain.end(), value);
    chain.insert(pos, value);
}

std::vector<unsigned int> PmergeMe::mergeInsertSortRecursiveVector(const std::vector<unsigned int>& input) {
    // Base case: 0 or 1 elements are already sorted
    if (input.size() <= 1)
        return input;
    
    // Step 1: Pair elements into smalls and larges
    std::vector<unsigned int> smalls;
    std::vector<unsigned int> larges;
    int leftover = -1;
    
    for (size_t i = 0; i + 1 < input.size(); i += 2) {
        unsigned int a = input[i];
        unsigned int b = input[i + 1];
        if (a < b) {
            smalls.push_back(a);
            larges.push_back(b);
        } else {
            smalls.push_back(b);
            larges.push_back(a);
        }
    }
    
    if (input.size() % 2 != 0) {
        leftover = input.back();
    }
    
    // Step 2: Create a deque from larges and recursively sort it
    std::vector<unsigned int> larges_deque(larges.begin(), larges.end());
    std::vector<unsigned int> main_chain = mergeInsertSortRecursiveVector(larges_deque);
    
    // Step 3: Insert smalls based on Jacobsthal order
    std::vector<unsigned int> insertion_order = getJacobsthalIndices(smalls.size());
    for (size_t i = 0; i < insertion_order.size(); ++i) {
        int index = insertion_order[i];
        if (index < (int)smalls.size()) {
            binaryInsertVector(main_chain, smalls[index]);
        }
    }
    // Step 4: Insert leftover if exists
    if (leftover != -1) {
        binaryInsertVector(main_chain, leftover);
    }
    
    return main_chain;
}

std::deque<unsigned int> PmergeMe::mergeInsertSortRecursiveDeque(const std::deque<unsigned int>& input) {
    // Base case: 0 or 1 elements are already sorted
    if (input.size() <= 1)
        return input;
    
    // Step 1: Pair elements into smalls and larges
    std::deque<unsigned int> smalls;
    std::deque<unsigned int> larges;
    int leftover = -1;
    
    for (size_t i = 0; i + 1 < input.size(); i += 2) {
        unsigned int a = input[i];
        unsigned int b = input[i + 1];
        if (a < b) {
            smalls.push_back(a);
            larges.push_back(b);
        } else {
            smalls.push_back(b);
            larges.push_back(a);
        }
    }
    
    if (input.size() % 2 != 0) {
        leftover = input.back();
    }
    
    // Step 2: Create a deque from larges and recursively sort it
    std::deque<unsigned int> larges_deque(larges.begin(), larges.end());
    std::deque<unsigned int> main_chain = mergeInsertSortRecursiveDeque(larges_deque);
    
    // Step 3: Insert smalls based on Jacobsthal order
    std::vector<unsigned int> insertion_order = getJacobsthalIndices(smalls.size());
    for (size_t i = 0; i < insertion_order.size(); ++i) {
        int index = insertion_order[i];
        if (index < (int)smalls.size()) {
            binaryInsertDeque(main_chain, smalls[index]);
        }
    }
    // Step 4: Insert leftover if exists
    if (leftover != -1) {
        binaryInsertDeque(main_chain, leftover);
    }
    
    return main_chain;
}

void PmergeMe::binaryInsertVector(std::vector<unsigned int>& chain, unsigned int value) {
    std::vector<unsigned int>::iterator pos = std::lower_bound(chain.begin(), chain.end(), value);
    chain.insert(pos, value);
}