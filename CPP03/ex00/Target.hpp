/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Target.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrizakov <mrizakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 19:01:19 by mrizakov          #+#    #+#             */
/*   Updated: 2024/02/18 19:01:20 by mrizakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef    TARGET_HPP
#define    TARGET_HPP

#include <iostream>

class Target
{
    public:
        Target(void);
        ~Target(void);
        Target(const Target& other);
        Target& operator=(const Target& other);

    private:
};

#endif
