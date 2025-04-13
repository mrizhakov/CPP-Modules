/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrizakov <mrizakov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 01:08:32 by mrizakov          #+#    #+#             */
/*   Updated: 2025/04/13 15:19:07 by mrizakov         ###   ########.fr       */
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
        this->data = NULL;
        this->n = 0;   

    };

    Array(unsigned int n) {
        this->data = new T[n]();
        this->n = n;
        
    };
    
    ~Array() {
        delete[] this->data;
        // delete data;
    };
    
    Array(const Array& other) {
        this->n = other.n;
        this->data = new T[this->n];
        for (unsigned int i = 0; i < this->n; i++)
        {
            this->data[i] = other.data[i];
        }
    };
    Array& operator=(const Array& other) {
        if (this != &other) {
            delete [] this->data;
            this->n = other.n;
            this->data = new T[this->n]();
            for (unsigned int i = 0; i <this->n; i++) {
                this->data[i] = other.data[i];
            }
        }
        return *this;
    };
    
    T& operator[](unsigned int pos) {
        if (pos >= n || pos < 0)
            throw std::exception();
        return this->data[pos];
    }

    unsigned int size(void) const {
        return this->n;
    };
    
};
