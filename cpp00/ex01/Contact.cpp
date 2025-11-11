/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeller- <ekeller-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 12:26:11 by ekeller-          #+#    #+#             */
/*   Updated: 2025/11/11 12:31:05 by ekeller-         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Contact.hpp"
#include <string>

void Contact::setContact( std::string fn, std::string ln,
        std::string nn, std::string pn, std::string ds) {
	this->_firstName = fn;
	this->_lastName = ln;
	this->_nickname = nn;
	this->_phoneNumber = pn;
	this->_darkSecret = ds;			
}

//return by value. returns a copy of the object. safer but more memory(O(n))
// if I used "const std::string& getFirstName() const;" there would be no
//copy
std::string Contact::getFirstName() const
{
    return _firstName;
}

std::string Contact::getLastName() const
{
    return _lastName;
}

std::string Contact::getNickname() const
{
    return _nickname;
}

std::string Contact::getPhoneNumber() const
{
    return _phoneNumber;
}

std::string Contact::getDarkSecret() const
{
    return _darkSecret;
}