/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrizakov <mrizakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 15:13:37 by mrizakov          #+#    #+#             */
/*   Updated: 2025/04/09 17:58:37 by mrizakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"




int main() {
    
    // Base *base = new Base;
    // A a();
    Base *random_base = generate();
    identify(random_base);


    // Base &random_base_ref = generate();
    identify(*random_base);

    

    
    return 0;
}
