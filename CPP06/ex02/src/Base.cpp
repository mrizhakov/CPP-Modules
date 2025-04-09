/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrizakov <mrizakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 01:07:18 by mrizakov          #+#    #+#             */
/*   Updated: 2025/04/09 22:13:35 by mrizakov         ###   ########.fr       */
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

Base * generate(void) 
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

void identify(Base* p) 
{
   if (dynamic_cast<A*>(p)) {
      std::cout << "Type A, using pointers to check" << std::endl;
   } else if (dynamic_cast<B*>(p)) {
      std::cout << "Type B, using pointers to check" << std::endl;
   } else if (dynamic_cast<C*>(p)) {
      std::cout << "Type C, using pointers to check" << std::endl;
   } else
   std::cout << "Some other class, using pointers to check" << std::endl;
}

void identify(Base& p) 
{
   try {
      (void)dynamic_cast<A&>(p);
      std::cout << "Type A, using references to check" << std::endl;
   }
   catch (...) {}
   try {
      (void)dynamic_cast<B&>(p);
      std::cout << "Type B, using references to check" << std::endl;
   }
   catch (...) {}
   try {
      (void)dynamic_cast<C&>(p);
      std::cout << "Type C, using references to check" << std::endl;
   }
   catch (...) {}
}

// In order not to use anything from <typeinfo> using catch (...) (catches all)
// Otherwise would have used catch (const std::bad_cast& e) with catch (...)