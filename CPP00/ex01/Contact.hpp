/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrizakov <mrizakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 15:13:31 by mrizakov          #+#    #+#             */
/*   Updated: 2024/02/05 21:10:24 by mrizakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP


#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <limits>

class Contact {
    
    public:
    Contact(void);
    ~Contact(void);
    void SetFirstName(std::string str);
    std::string GetFirstName(void) const;
    void SetLastName(std::string str);
    std::string GetLastName(void) const;
    void SetNickname(std::string str);
    std::string GetNickname(void) const;
    void SetPhoneNumber(std::string str);
    std::string GetPhoneNumber(void) const;
    void SetSecret(std::string str);
    std::string GetSecret(void) const;

    private:
    std::string _first_name;
    std::string _last_name;
    std::string _nickname;
    std::string _phone_number;
    std::string _secret;
};

#endif // CONTACT_HPP