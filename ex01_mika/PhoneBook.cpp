/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elianmik <elianmik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 10:46:08 by elianemika8       #+#    #+#             */
/*   Updated: 2025/07/01 14:17:35 by elianmik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : contactCount(0), index(0) {}

void PhoneBook::addContact()
{
    std::string firstName, lastName, nickname, phoneNumber, darkestSecret;

    std::cout << "First name: ";
    std::getline( std::cin, firstName );
    std::cout << "Last name: ";
    std::getline( std::cin, lastName );
    std::cout << "Nickname: ";
    std::getline( std::cin, nickname );
    std::cout << "Phone number: ";
    std::getline( std::cin, phoneNumber );
    std::cout << "Darkest secret: ";
    std::getline( std::cin, darkestSecret );

    if (firstName.empty() || lastName.empty() || nickname.empty()
    || phoneNumber.empty() || darkestSecret.empty())
    {
        std::cout << "All fields must be filled!" << std::endl;
        return;
    }

    if (!isAlphaString( firstName ) || !isAlphaString( lastName ) || !isAlphaString( nickname ))
    {
        std::cout << "First name, last name and nickname must contain only letters!" << std::endl;
        return;
    }

    if (!isNumericString( phoneNumber ))
    {
        std::cout << "Phone number must contain only digits!" << std::endl;
        return;
    }
    
    if (index == 8)
        index = 0;
    contacts[index].setContact( firstName, lastName, nickname, phoneNumber, darkestSecret );
    index++;
    
    if (contactCount < 8)
        contactCount++;
    std::cout << "Contact added!" << std::endl;
}

// formatField ensures each string fits exactly in a 10-character column.
// If the string is longer than 10 chars, it is truncated and ends with a dot.
// If it is shorter, it is left-padded with spaces to align to the right.
std::string PhoneBook::formatField( const std::string &str )
{
    if (str.length() > 10)
        // str.substr(0, 9) returns a substring
        // starting at index 0 with a length of 9 characters.
        return str.substr( 0, 9 ) + ".";
    return std::string( 10 - str.length(), ' ' ) + str;
}

void PhoneBook::displayContacts() const
{
    std::cout << "---------------------------------------------" << std::endl;
    std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
    std::cout << "---------------------------------------------" << std::endl;

    for (int i = 0; i < contactCount; ++i)
    {
        // std::setw(10) sets the width of the next output field to 10 chars.
        // If value is shorter than 10, it is right-aligned & padded with spaces.
        // It only affects the very next item sent to the output stream.
        std::cout << "|" << std::setw( 10 ) << i
                  << "|" << formatField( contacts[i].getFirstName() )
                  << "|" << formatField( contacts[i].getLastName() )
                  << "|" << formatField( contacts[i].getNickname() )
                  << "|" << std::endl;
    }
    std::cout << "---------------------------------------------" << std::endl;
}

void PhoneBook::displayContactDetails( int i ) const
{
    if (i < 0 || i >= contactCount)
    {
        std::cout << "Invalid index!" << std::endl;
        return;
    }
    std::cout << "First Name: " << contacts[i].getFirstName() << std::endl;
    std::cout << "Last Name: " << contacts[i].getLastName() << std::endl;
    std::cout << "Nickname: " << contacts[i].getNickname() << std::endl;
    std::cout << "Phone Number: " << contacts[i].getPhoneNumber() << std::endl;
    std::cout << "Darkest Secret: " << contacts[i].getDarkestSecret() << std::endl;
}
