/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrizakov <mrizakov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 01:08:32 by mrizakov          #+#    #+#             */
/*   Updated: 2025/05/06 20:37:35 by mrizakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <stack>

enum Operands {
    ADD,
    SUBSTR,
    MULT,
    DIV
};

class RPN
{
private:
    std::stack<int> stack;

    RPN(const RPN &other);
    RPN &operator=(const RPN &other);
    void readInputLine() const;
    void checkArgs(int argc) const;
    void outputResult(std::stack<int> stack) const;


public:
    RPN(void);
    ~RPN(void);
    void runCalculator(int argc, char *argv[]);
    void tokenizeInputLine(char *argv);
    void printStack(std::stack<int> stack);

};
