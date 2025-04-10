/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrizakov <mrizakov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 01:08:32 by mrizakov          #+#    #+#             */
/*   Updated: 2025/04/11 00:15:28 by mrizakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include <exception>

template <typename T>

class Array {

private:
    T* data;
    unsigned int n;
    
public:
    Array() {
        T *data = new T();    
        (void)data;

    };

    Array(unsigned int n) {
        T *data = new T[n];
        (void)data;
    };
    
    ~Array() {
        // delete data;
    };
    
    Array(const Array& other) {
        if (data != other.data)
        {
            data = other.data;
        }
    };
    Array& operator=(const Array& other) {
            if (this != &other) {
            data = other.data;
        }
    return *this;
    };
    
    T& operator[](unsigned int pos) {
        if (pos >= n)
            throw std::exception();
        return data[pos];
    }

    unsigned int size(void) const {
        return n;
    };
    
};
