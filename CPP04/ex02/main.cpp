/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrizakov <mrizakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 15:13:37 by mrizakov          #+#    #+#             */
/*   Updated: 2024/03/03 14:04:44 by mrizakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main(void)
{

    //Animal animal;
    

    
    const int array_size = 2;
    int t = array_size;
    AAnimal *zoo[t];
    while(t != 0)
    {
        if (t % 2 == 0)
            zoo[t] = new Dog();
        else
            zoo[t] = new Cat();
        zoo[t]->makeSound();
        t--;
    }
    int e = array_size;
    while(e != 0)
    {
        delete zoo[e];
        e--;
    }

    
    const AAnimal* j = new Dog();
    Cat *i = new Cat();

    i->giveIdeas("Mice!", 0);
    i->giveIdeas("Cheese!", 1);
    
    Cat *d(i);

    d->checkIdeas(0);
    d->checkIdeas(1);


    Dog a;
    a.giveIdeas("Mice!", 0);
    a.giveIdeas("Cheese!", 1);

    a.checkIdeas(0);
    a.checkIdeas(1);


    Dog a1 = a;
    // a1 = a;
    std::cout << "a1 copied" << std::endl;
    a1.checkIdeas(0);
    a.checkIdeas(1);

    Dog a2(a);
    std::cout << "a2 copied" << std::endl;
    a2.checkIdeas(0);
    a.checkIdeas(1);



    Dog b;
    b.giveIdeas("Rabbits!", 0);
    b.checkIdeas(0);

    
    
    delete j; //should not create a leak
    delete i;
    
    return(0);
}

