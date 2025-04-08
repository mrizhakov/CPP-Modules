/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrizakov <mrizakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 15:13:37 by mrizakov          #+#    #+#             */
/*   Updated: 2025/04/09 00:52:05 by mrizakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"


int main() {
    // Create an integer variable
    int number = 42;
    
    // Get a pointer to this variable
    int* ptr = &number;
    
    // Convert the pointer to uintptr_t (pointer → integer)
    uintptr_t ptr_as_integer = reinterpret_cast<uintptr_t>(ptr);
    
    // Print the values
    std::cout << "Original pointer value: " << ptr << std::endl;
    std::cout << "Pointer as integer: " << ptr_as_integer << std::endl;
    
    // Convert back to a pointer (integer → pointer)
    int* recovered_ptr = reinterpret_cast<int*>(ptr_as_integer);
    
    // Use the recovered pointer
    std::cout << "Value accessed through recovered pointer: " << *recovered_ptr << std::endl;
    std::cout << std::endl;

    
    Data *data = new Data;
    data->some_data = "more data";
    std::cout << "Original data located at data->some_data: " << data->some_data << std::endl;
    std::cout << std::endl;

    uintptr_t some_pointer;
    
    some_pointer = Serializer::serialize(data);
    Data *new_data(Serializer::deserialize(some_pointer));
    std::cout << "After serializing data to a uintptr_t and back to a new Data type data is located at new_data->some_data :" << new_data->some_data << std::endl;
    delete data;
    
    return 0;
}
