/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrizakov <mrizakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 15:13:31 by mrizakov          #+#    #+#             */
/*   Updated: 2024/02/03 17:03:52 by mrizakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_CLASS_H
# define PHONEBOOK_CLASS_H

# include<iostream>
# include<string>

class Contact {
    public:
    std::string first_name;
    std::string last_name;
    std::string nickname;
    std::string secret;
    std::string phone_number;
    Contact(void);
    ~Contact(void);
};

class Phonebook {

public:
    Phonebook(void);
    ~Phonebook(void);
    void        AddContact(void);
    void        DisplayContact(unsigned int search_number) const;
    void        PressEnterToContinue(void);
    Contact     contact_list[8];
    static int  getNbContacts(void);
    void        incrementContacts(void);

private:
    static int _nbContacts;
};

int Phonebook::getNbContacts(void) {
    return Phonebook::_nbContacts;
}

int Phonebook::_nbContacts = 0;

#endif