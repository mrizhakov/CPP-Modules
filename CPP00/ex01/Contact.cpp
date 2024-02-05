/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrizakov <mrizakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 15:13:37 by mrizakov          #+#    #+#             */
/*   Updated: 2024/02/04 18:46:07 by mrizakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Contact.hpp"


Contact::Contact(void) {
    this->_first_name  = "";
    this->_last_name = "";
    this->_nickname = "";
    this->_secret = "";
    this->_phone_number = "";
    return;
}

Contact::~Contact(void) {
    return;
}

void Contact::SetFirstName(std::string str) {
    this->_first_name = str;
}

std::string Contact::GetFirstName(void) const {
    return this->_first_name;
}

void Contact::SetLastName(std::string str) {
    this->_last_name = str;
}

std::string Contact::GetLastName(void) const {
    return this->_last_name;
}

void Contact::SetNickname(std::string str) {
    this->_nickname = str;
}

std::string Contact::GetNickname(void) const {
    return this->_nickname;
}

void Contact::SetPhoneNumber(std::string str) {
    this->_phone_number = str;
}

std::string Contact::GetPhoneNumber(void) const {
    return this->_phone_number;
}

void Contact::SetSecret(std::string str) {
    this->_secret = str;
}

std::string Contact::GetSecret(void) const {
    return this->_secret;
}

