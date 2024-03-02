/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrizakov <mrizakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 15:13:37 by mrizakov          #+#    #+#             */
/*   Updated: 2024/03/01 21:19:52 by mrizakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"
#include "Cat.hpp"



int main(void)
{
    // Animal a;
    // a.makeSound();
    // Cat c;
    const Animal* meta = new Animal();
    // const Animal* j = new Animal();
    // const Animal* i = new Animal();
    // const Animal* j = new Dog();
    const Animal* i = new Cat();
    // std::cout << j->getType() << " type" << std::endl;
    // std::cout << i->getType() << " type" << std::endl;
    i->makeSound(); //will output the cat sound!
    // j->makeSound();
    meta->makeSound();

    // delete j;
    delete meta;
    delete i;
    //delete meta;
    
    return(0);
}

