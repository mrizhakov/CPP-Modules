/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrizakov <mrizakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 15:13:37 by mrizakov          #+#    #+#             */
/*   Updated: 2024/08/12 01:04:12 by mrizakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"


int main(void)
{
    Intern Daniil;
    AForm* randomForm;
    randomForm = Daniil.makeForm("robotomy request", "Bender");
    Bureaucrat BigFish = Bureaucrat("BigFish", 1);
    Bureaucrat SmallFish = Bureaucrat("SmallFish", 150);

    randomForm->beSigned(BigFish);
    randomForm->execute(BigFish);
    try {
    randomForm->beSigned(SmallFish);
    randomForm->execute(SmallFish);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    
    try {
    AForm* randomForm2 = Daniil.makeForm("lobotomy request", "Bender");
    (void)randomForm2;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    AForm* randomForm3 = Daniil.makeForm("shrubbery creation", "Bender");
    randomForm3->beSigned(BigFish);
    randomForm3->execute(BigFish);

    delete randomForm;
    delete randomForm3;


    return(0);
}

