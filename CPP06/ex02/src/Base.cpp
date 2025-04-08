/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrizakov <mrizakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 01:07:18 by mrizakov          #+#    #+#             */
/*   Updated: 2025/04/09 01:45:46 by mrizakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"



Base::Base(void) {}

Base::~Base(void) {}

Base::Base(const Base& other)
{
   (void)other;
   *this = other;
}

Base&    Base::operator=(const Base& other)
{
   (void)other;
   return *this;
}

Base * Base::generate(void) 
{
   std::srand(time(NULL));
   int random_number = std::rand() % 3;
   switch (random_number) {
      case 0:
         return new A;
      case 1:
         return new B;
      case 2:
         return new C;
      default:
         return NULL;   
   }
}

void Base::identify(Base* p) 
{
   (void)p;

}

void Base::identify(Base& p) 
{
   (void)p;

}