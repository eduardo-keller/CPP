/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elianmik <elianmik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 10:45:34 by elianemika8       #+#    #+#             */
/*   Updated: 2025/07/01 14:15:19 by elianmik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// This .cpp file is used for implementations.
// Here, u provide actual code (definitions) for methods declared in .hpp file.

// - Implement the logic of the class methods declared in the .hpp file
// - Include the corresponding header file (e.g., #include "Contact.hpp")

#include "Contact.hpp"

void Contact::setContact( std::string fn, std::string ln,
    std::string nn, std::string pn, std::string ds )
{
    this->firstName = fn;
    this->lastName = ln;
    this->nickname = nn;
    this->phoneNumber = pn;
    this->darkestSecret = ds;
}

std::string Contact::getFirstName() const
{
    return firstName;
}

std::string Contact::getLastName() const
{
    return lastName;
}

std::string Contact::getNickname() const
{
    return nickname;
}

std::string Contact::getPhoneNumber() const
{
    return phoneNumber;
}

std::string Contact::getDarkestSecret() const
{
    return darkestSecret;
}
