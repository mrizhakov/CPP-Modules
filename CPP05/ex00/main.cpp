/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrizakov <mrizakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 15:13:37 by mrizakov          #+#    #+#             */
/*   Updated: 2024/08/05 14:53:58 by mrizakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"


int main(void)
{
    Bureaucrat A = Bureaucrat("Paper whisperer", 3);
    std::cout << A << std::endl;

    A.incrementGrade();
    std::cout << A << std::endl;

    A.incrementGrade();
    std::cout << A << std::endl;

    A.decrementGrade();
    std::cout << A << std::endl;

    A.decrementGrade();
    A.decrementGrade();
    A.decrementGrade();
    A.decrementGrade();
    Bureaucrat B = Bureaucrat("Paper massager", 150);
    B.incrementGrade();
    std::cout << A << std::endl;

    try {
        Bureaucrat C = Bureaucrat("Document afficionado", 1);
        Bureaucrat D = Bureaucrat("Document afficionado", 151);
        std::cout << C << std::endl;
    } catch (Bureaucrat::GradeTooHighException& e) {
        std::cout << e.what() << std::endl;
    } catch (Bureaucrat::GradeTooLowException& e) {
        std::cout << e.what() << std::endl;
    } catch (std::exception &e) {
        
    }
    // std::cout << A << std::endl;

    return(0);
}

