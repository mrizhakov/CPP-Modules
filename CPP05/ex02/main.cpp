/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrizakov <mrizakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 15:13:37 by mrizakov          #+#    #+#             */
/*   Updated: 2024/08/09 17:38:46 by mrizakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"



int main(void)
{
    Bureaucrat A = Bureaucrat("Paper whisperer", 149);
    std::cout << A << std::endl;

    Form Fa = Form("Leave", false, 150, 150);
    std::cout << Fa << std::endl;


    A.signForm(Fa);
    A.decrementGrade();
    A.signForm(Fa);
    A.incrementGrade();
    A.signForm(Fa);

    try {
        Form Fa1 = Form("Bad form", false, 151, 15235);
        std::cout << Fa1 << std::endl;
    } catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
        // std::cout << Fa1 << std::endl;
    }

    // Form Fa2 = Form("Really bad form", false, -5, 15235);
    // std::cout << Fa2 << std::endl;


    return(0);
}

