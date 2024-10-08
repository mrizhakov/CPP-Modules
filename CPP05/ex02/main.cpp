/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrizakov <mrizakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 15:13:37 by mrizakov          #+#    #+#             */
/*   Updated: 2024/08/11 23:00:02 by mrizakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"


int main(void)
{
    ShrubberyCreationForm A = ShrubberyCreationForm("test");
    ShrubberyCreationForm B = ShrubberyCreationForm("test2");

    Bureaucrat SmallFish = Bureaucrat("SmallFish", 150);
    Bureaucrat BigFish = Bureaucrat("BigFish", 1);


    Bureaucrat ShrubberySigner = Bureaucrat("ShrubberySigner", 145);
    Bureaucrat ShrubberyExecutor = Bureaucrat("ShrubberyExecutor", 137);
    A.beSigned(ShrubberySigner);
    A.execute(ShrubberyExecutor);
    try {
        B.beSigned(SmallFish);
        B.execute(SmallFish);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    B.beSigned(BigFish);
    B.execute(BigFish);
    ShrubberyCreationForm Noname = ShrubberyCreationForm();
    Noname.beSigned(BigFish);
    Noname.execute(BigFish);

    RobotomyRequestForm DefaultRobotomy = RobotomyRequestForm("RobotomyDefaultRequest");
    DefaultRobotomy.beSigned(BigFish);
    DefaultRobotomy.execute(BigFish);

    PresidentialPardonForm PresidentialPardon = PresidentialPardonForm("Max");
    PresidentialPardon.beSigned(BigFish);
    PresidentialPardon.execute(BigFish);
    try {
        PresidentialPardon.beSigned(SmallFish);
        PresidentialPardon.execute(BigFish);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    Bureaucrat RandomDude = Bureaucrat();

    
    return(0);
}

