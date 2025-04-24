/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrizakov <mrizakov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 01:08:32 by mrizakov          #+#    #+#             */
/*   Updated: 2025/04/23 23:37:03 by mrizakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <string>
#include "Test.hpp"


Test::Test() : value(0), id("default") {};

Test::Test(int v, std::string name) : value(v), id(name) {};

Test::Test(const Test& other) : value(other.value), id(other.id){
    (void)other;
};

Test& Test::operator=(const Test& other) {
    if (this != &other) {
        value = other.value;
        id = other.id;
    }
    return *this;
};

Test::~Test() {};


bool Test::operator<=(const Test& other) {
    return value <= other.value;
};

bool Test::operator>=(const Test& other) {
    return value >= other.value;
};