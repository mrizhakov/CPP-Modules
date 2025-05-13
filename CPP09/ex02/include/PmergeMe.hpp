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

    PmergeMe(const PmergeMe &other);
    PmergeMe &operator=(const PmergeMe &other);

    void checkArgs(int argc, char *argv[]);




    // void readInputLine() const;
    // void outputResult(std::stack<int> stack) const;
    // void pushAndCalculate(char *argv);
    void printDeque(std::deque<unsigned int> pmerge_deque);

public:
    PmergeMe(void);
    ~PmergeMe(void);
    void runCalculator(int argc, char *argv[]);
};
