/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrizakov <mrizakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 15:13:31 by mrizakov          #+#    #+#             */
/*   Updated: 2024/02/05 21:09:34 by mrizakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <limits>
#include "Contact.hpp"

void        PressEnterToContinue(void);
bool        IsWhitespace(char c);
bool        StringEmptyOrWhitespace(std::string &str);
std::string AcceptNonEmptyString(void);
std::string InputValidatedPhoneNumber(void);

class Phonebook {

public:
    Phonebook(void) ;
    ~Phonebook(void);
    void        Execute(void);
    
private:
    int _nbContacts;
    Contact     _contact_list[8];
    void        DisplayAllContacts(unsigned int search_number) const;
    void        AddContact(void);
    int         GetNbContacts(void) const;
    void        SearchContact(void) const;
    void        IncrementContacts(void);
};

#endif //PHONEBOOK_HPP