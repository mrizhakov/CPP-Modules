/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrizakov <mrizakov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 01:08:32 by mrizakov          #+#    #+#             */
/*   Updated: 2025/05/06 20:37:35 by mrizakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
// #include <stack>
#include <deque>
#include <vector>



class PmergeMe
{
private:
    std::deque<unsigned int> pmerge_deque;
    std::vector<unsigned int> pmerge_vector;

    PmergeMe(const PmergeMe &other);
    PmergeMe &operator=(const PmergeMe &other);

    void checkArgs(int argc, char *argv[]);
    void checkArgsVector(int argc, char *argv[]);

    void printDeque(std::deque<unsigned int> pmerge_deque);
    void printVector(std::vector<unsigned int> pmerge_vector);

    std::vector<unsigned int> getJacobsthalIndexes(unsigned int n);

    void binaryInsertDeque(std::deque<unsigned int>& chain, unsigned int value);
    void binaryInsertVector(std::vector<unsigned int>& chain, unsigned int value);

    std::deque<unsigned int> mergeInsertSortRecursiveDeque(const std::deque<unsigned int>& input);
    std::vector<unsigned int> mergeInsertSortRecursiveVector(const std::vector<unsigned int>& input);

public:
    PmergeMe(void);
    ~PmergeMe(void);
    void runMergeInsertSort(int argc, char *argv[]);
};
