/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Test.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrizakov <mrizakov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 01:08:32 by mrizakov          #+#    #+#             */
/*   Updated: 2025/04/10 21:35:13 by mrizakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>

class Test {
public:
    int value;
    std::string id;
    
    Test();
    Test(int v, std::string name);
    Test(const Test& other);
    Test& operator=(const Test& other);
    ~Test();
    
    bool operator<=(const Test& other);
    bool operator>=(const Test& other);
};