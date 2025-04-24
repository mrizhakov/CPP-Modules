/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrizakov <mrizakov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 12:04:31 by mrizakov          #+#    #+#             */
/*   Updated: 2025/04/23 23:39:29 by mrizakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <MutantStack.hpp>
#include <Test.hpp>
#include <iostream>
#include <list>
#include <cstdlib>
#include <ctime>
#include <sstream>



int main()
{
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
    std::cout << *it << std::endl;
    ++it;
    }
    std::stack<int> s(mstack);


    MutantStack<Test> mstack_obj;
    srand(time(NULL));  // Use current time as seed

    for (int i = 0; i < 5; i++)
    {
        std::stringstream ss;
        ss << "Different strings " << rand();
        std::string word = ss.str();
        Test test(rand(), word);
        std::cout << "Creating Test object with value: " << test.value << " and ID: " << test.id << std::endl;
        mstack_obj.push(test);
    }
    std::cout << "MutantStack<Test> mstack_obj size is "<< mstack_obj.size() << std::endl;
    MutantStack<Test>::iterator it1 = mstack_obj.begin();
    MutantStack<Test>::iterator ite1 = mstack_obj.end();
    // ++it1;
    // --it1;
    while (it1 != ite1) {
            std::cout << "Value: " << it1->value << ", ID: " << it1->id << std::endl;
            ++it1;
        }
    

    // std::list<int> mstack;
    // mstack.push_back(5);
    // mstack.push_back(17);
    // std::cout << mstack.back() << std::endl;
    // mstack.pop_back();
    // std::cout << mstack.size() << std::endl;
    // mstack.push_back(3);
    // mstack.push_back(5);
    // mstack.push_back(737);
    // //[...]
    // mstack.push_back(0);
    // std::list<int>::iterator it = mstack.begin();
    // std::list<int>::iterator ite = mstack.end();
    // ++it;
    // --it;
    // while (it != ite)
    // {
    // std::cout << *it << std::endl;
    // ++it;
    // }
    // std::list<int> s(mstack);
    return 0;
}