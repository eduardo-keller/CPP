/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeller-@student.42sp.org.br <ekeller-@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 12:26:11 by ekeller-          #+#    #+#             */
/*   Updated: 2025/11/05 16:47:50 by ekeller-@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void Contact::setContact( std::string fn, std::string ln,
        std::string nn, std::string pn, std::string ds) {
	this->_firstName = fn;
	this->_lastName = ln;
	this->_nickname = nn;
	this->_phoneNumber = pn;
	this->_darkSecret = ds;			
}

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

std::string Contact::getDarkestSecret() const
{
    return _darkSecret;
}