/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrizakov <mrizakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 15:13:37 by mrizakov          #+#    #+#             */
/*   Updated: 2024/02/05 21:12:58 by mrizakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Phonebook.hpp"

void PressEnterToContinue(void) {
    std::string input_str;
    std::cout << "Press Enter to continue...";
    std::getline(std::cin, input_str);
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    system("clear");
}

bool    IsWhitespace(char c) {
    return std::isspace(static_cast<unsigned char>(c)) != 0;
}

bool    StringEmptyOrWhitespace(std::string &str) {

    std::string::iterator i = str.begin();
    if (*i == '\0')
        return (1);
    while (i != str.end())
    {
        if (!IsWhitespace(*i))
            return (0);        
        i++;
    }
    return(1);
}

std::string AcceptNonEmptyString(void) {
    std::string input_str;
    std::getline(std::cin, input_str);
    while (StringEmptyOrWhitespace(input_str))
        std::getline(std::cin, input_str);
    return (input_str);
}

std::string InputValidatedPhoneNumber(void) {
    char *endptr;
    std::string input_str;
    input_str = AcceptNonEmptyString();
    strtoull(input_str.c_str(), &endptr, 10);
    while (*endptr != '\0') 
    {
        std::cout << "Invalid phone number, try again" << std::endl;
        input_str = AcceptNonEmptyString();
        strtoull(input_str.c_str(), &endptr, 10);
    }
    return (input_str);
}

Phonebook::Phonebook(void) {
    _nbContacts = 0;
}

Phonebook::~Phonebook(void) {
}

void Phonebook::Execute(void) {
    std::string command;
    int i = 0;

    system("clear");
    while (true)
    {
        std::cout << "To use the Phonebook, use commands or aliases:" << std::endl;
        std::cout << "1. ADD" << std::endl;
        std::cout << "2. SEARCH" << std::endl;
        std::cout << "3. EXIT" << std::endl;
        std::getline(std::cin, command);

        if (command == "EXIT" || command == "3")
            break ;
        else if (command == "ADD" || command == "1" )
        {
            system("clear");
            AddContact();
            PressEnterToContinue();
        }
        else if (command == "SEARCH" || command == "2")
        {
            system("clear");
            i = 0;
            std::cout << "|     Index|First name| Last name|  Nickname|" << std::endl;
            while (i != 8)
            {
                DisplayAllContacts(i);
                i++;
            }
            SearchContact();
        }
    }
}

void Phonebook::AddContact(void) {
    std::string input_str;
    
    std::cout << "Input contact information one line at a time: " << std::endl;
    std::cout << "1. First name" << std::endl;
    input_str = AcceptNonEmptyString();
    _contact_list[GetNbContacts()].SetFirstName(input_str);
    
    std::cout << "2. Last name" << std::endl;
    input_str = AcceptNonEmptyString();
    _contact_list[GetNbContacts()].SetLastName(input_str);
    
    std::cout << "3. Nickname" << std::endl;
    input_str = AcceptNonEmptyString();
    _contact_list[GetNbContacts()].SetNickname(input_str);

    std::cout << "4. Phone number" << std::endl;
    input_str = InputValidatedPhoneNumber();
    _contact_list[GetNbContacts()].SetPhoneNumber(input_str);
    
    std::cout << "5. Darkest secret" << std::endl;
    input_str = AcceptNonEmptyString();
    _contact_list[GetNbContacts()].SetSecret(input_str);
    
    std::cout << "Contact added succesfully!" << std::endl;
    IncrementContacts();
    if (GetNbContacts() == 8)
        _nbContacts = 0;
    return;
}

void Phonebook::IncrementContacts(void) {
    if (this->_nbContacts == 8)
        this->_nbContacts = 0;
    else
        this->_nbContacts++;
    return;
}

void Phonebook::DisplayAllContacts(unsigned int search_number) const {
    
    std::cout << "|" << std::setw(10) << search_number  << "|";
    if (_contact_list[search_number].GetFirstName().size() > 10)
        std::cout << _contact_list[search_number].GetFirstName().substr(0,9) << ".";
    else
        std::cout << std::setw(10) << _contact_list[search_number].GetFirstName();
    std::cout << "|";
    if (_contact_list[search_number].GetLastName().size() > 10)
        std::cout << _contact_list[search_number].GetLastName().substr(0,9) << ".";
    else
        std::cout << std::setw(10) << _contact_list[search_number].GetLastName();
    std::cout << "|";
    if (_contact_list[search_number].GetNickname().size() > 10)
        std::cout << _contact_list[search_number].GetNickname().substr(0,9) << ".";
    else
        std::cout << std::setw(10) << _contact_list[search_number].GetNickname();
    std::cout << "|";
    std::cout << std::endl;
}

void Phonebook::SearchContact() const {
    int search_number;
    
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
        else if (search_number >= 0 && search_number <= 7)
        {
            system("clear");
            std::cout << "Contact " << search_number << " info:" << std::endl;
            std::cout << "First name: " << this->_contact_list[search_number].GetFirstName() << std::endl;
            std::cout << "Last name: " << this->_contact_list[search_number].GetLastName() << std::endl;
            std::cout << "Nickname: " << this->_contact_list[search_number].GetNickname() << std::endl;
            std::cout << "Phone number: " << this->_contact_list[search_number].GetPhoneNumber() << std::endl;
            std::cout << "Darkest secret: " << this->_contact_list[search_number].GetSecret() << std::endl;                
            PressEnterToContinue();
            break;
        }
    }
}

int Phonebook::GetNbContacts(void) const {
    return Phonebook::_nbContacts;
}