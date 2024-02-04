/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrizakov <mrizakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 15:13:37 by mrizakov          #+#    #+#             */
/*   Updated: 2024/02/03 18:40:02 by mrizakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <limits>
#include "Phonebook.class.hpp"

Phonebook::Phonebook(void) {
    return;
}

Phonebook::~Phonebook(void) {
    return;
}

Contact::Contact(void) {
    return;
}

Contact::~Contact(void) {
    return;
}

void Phonebook::AddContact(void) {
    char *endptr;
    
    std::cout << "Input contact information one line at a time: " << std::endl;
    std::cout << "1. First name" << std::endl;
    std::cin >> contact_list[getNbContacts()].first_name;
    std::cout << "2. Last name" << std::endl;
    std::cin >> contact_list[getNbContacts()].last_name;
    std::cout << "3. Nickname" << std::endl;
    std::cin >> contact_list[getNbContacts()].nickname;
    std::cout << "4. Phone number" << std::endl;
    std::cin >> contact_list[getNbContacts()].phone_number;
    strtoull(contact_list[getNbContacts()].phone_number.c_str(), &endptr, 10);
    while (*endptr != '\0') 
    {
        std::cout << "Invalid phone number, try again" << std::endl;
        std::cin >> contact_list[getNbContacts()].phone_number;
        strtoull(contact_list[getNbContacts()].phone_number.c_str(), &endptr, 10);
    }
    std::cout << "5. Darkest secret" << std::endl;
    std::cin >> contact_list[getNbContacts()].secret;
    std::cout << "Contact added succesfully!" << std::endl;
    incrementContacts();
    if (getNbContacts() == 8)
        _nbContacts = 0;
    return;
}
void Phonebook::incrementContacts(void) {
    if (this->_nbContacts == 8)
        this->_nbContacts = 0;
    else
        this->_nbContacts++;
    return;
}

void Phonebook::DisplayContact(unsigned int search_number) const {
    

    std::cout << "|" << std::setw(10) << search_number  << "|";
    if (contact_list[search_number].first_name.size() > 10)
        std::cout << contact_list[search_number].first_name.substr(0,9) << ".";
    else
        std::cout << std::setw(10) << contact_list[search_number].first_name;
    std::cout << "|";
    if (contact_list[search_number].last_name.size() > 10)
        std::cout << contact_list[search_number].last_name.substr(0,9) << ".";
    else
        std::cout << std::setw(10) << contact_list[search_number].last_name;
    std::cout << "|";
    if (contact_list[search_number].nickname.size() > 10)
        std::cout << contact_list[search_number].nickname.substr(0,9) << ".";
    else
        std::cout << std::setw(10) << contact_list[search_number].nickname;
    std::cout << "|";
    std::cout << std::endl;
}

void Phonebook::PressEnterToContinue(void) {
    std::cout << "Press Enter to continue...";
    std::cin.get();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    system("clear");

}

int main(void)
{
    Phonebook   my_phonebook;
    std::string command = "";
    std::string first_name  = "";
    std::string last_name = "";
    std::string nickname = "";
    std::string secret = "";
    std::string phone_number = "";
    int i = 0;
    int search_number;

    system("clear");
    while (true)
    {
        std::cout << "To use the Phonebook, use commands or aliases:" << std::endl;
        std::cout << "1. ADD" << std::endl;
        std::cout << "2. SEARCH" << std::endl;
        std::cout << "3. EXIT" << std::endl;
        std::cin >> command;

        if (command == "EXIT" || command == "3")
            break ;
        else if (command == "ADD" || command == "1" )
        {
            system("clear");
            my_phonebook.AddContact();
            my_phonebook.PressEnterToContinue();
        }
        else if (command == "SEARCH" || command == "2")
        {
            system("clear");
            i = 0;
            std::cout << "|     Index|First name| Last name|  Nickname|" << std::endl;
            while (i != 8)
            {
                my_phonebook.DisplayContact(i);
                i++;
            }
            std::cout << "Input the number of the contact you would like to display: " << std::endl;
            while (true)
            {
                if (!(std::cin >> search_number))
                {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Invalid input, try again" << std::endl;
                }
                else if(!(search_number >= 0 && search_number <= 7))
                    std::cout << "This phonebook has only up to 8 contacts, please input numbers 0-7 (yes, this a 0-based phonebook): " << std::endl;
                else 
                {
                    system("clear");
                    std::cout << "Contact " << search_number << " info:" << std::endl;
                    std::cout << "First name: " << my_phonebook.contact_list[search_number].first_name << std::endl;
                    std::cout << "Last name: " << my_phonebook.contact_list[search_number].last_name << std::endl;
                    std::cout << "Nickname: " << my_phonebook.contact_list[search_number].nickname << std::endl;
                    std::cout << "Phone number: " << my_phonebook.contact_list[search_number].phone_number << std::endl;
                    std::cout << "Darkest secret: " << my_phonebook.contact_list[search_number].secret << std::endl;                
                    break;
                }
            }
            search_number = 0;
            my_phonebook.PressEnterToContinue();
        }
        else
            system("clear");
    }
    return(0);
}