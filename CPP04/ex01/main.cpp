/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrizakov <mrizakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 15:13:37 by mrizakov          #+#    #+#             */
/*   Updated: 2024/03/03 00:47:37 by mrizakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main(void)
{
    // const Animal* meta = new Animal();
    // const Animal* j = new Dog();
    // const Animal* i = new Cat();
    // std::cout << j->getType() << " " << std::endl;
    // std::cout << i->getType() << " " << std::endl;
    // i->makeSound(); //will output the cat sound!
    // j->makeSound();
    // meta->makeSound();

    // delete i;
    // delete j;
    // delete meta;

    

    // const WrongAnimal* wmeta = new WrongAnimal();
    // const WrongAnimal* wj = new WrongDog();
    // const WrongAnimal* wi = new WrongCat();
    // std::cout << wj->getType() << " " << std::endl;
    // std::cout << wi->getType() << " " << std::endl;
    // wi->makeSound(); //will output the cat sound!
    // wj->makeSound();
    // wmeta->makeSound();
    
    // delete wi;
    // delete wj;
    // delete wmeta;

    
    const int array_size = 2;
    int t = array_size;
    Animal *zoo[t];
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

    
    const Animal* j = new Dog();
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

