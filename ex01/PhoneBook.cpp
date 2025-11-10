/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeller- <ekeller-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 11:25:24 by ekeller-          #+#    #+#             */
/*   Updated: 2025/11/10 15:09:10 by ekeller-         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : _contactCount(0), _index(0) {}

void PhoneBook::addContact(){
	std::string firstName, lastName, nickname, phoneNumber, darkSecret;
	
	std::cout << "first name: ";
	std::getline(std::cin, firstName);
	std::cout << "lastname: ";
	std::getline(std::cin, lastName);
	std::cout << "nickname: ";
	std::getline(std::cin, nickname);
	std::cout << "phone number: ";
	std::getline(std::cin, phoneNumber);
	std::cout << "darkest secret: ";
	std::getline(std::cin, darkSecret);
	

    if (firstName.empty() || lastName.empty() || nickname.empty()
    || phoneNumber.empty() || darkSecret.empty()) {
        std::cout << "All fields must be filled!" << std::endl;
        return;
    }	
	if (!isAlphaString(firstName) || !isAlphaString(lastName) || !isAlphaString(nickname)) {
		std::cout << "First name, last name and nickname must contain only letters!" << std::endl;
		return;
	}
	if (!isNumericString( phoneNumber ))
    {
        std::cout << "Phone number must contain only digits!" << std::endl;
        return;
    }
    if (_index == 8)
        _index = 0;
	
    _contacts[_index].setContact( firstName, lastName, nickname, phoneNumber, darkSecret);
    _index++;
    if (_contactCount < 8)
        _contactCount++;
    std::cout << "Contact added!" << std::endl;
}

std::string PhoneBook::formatField( const std::string &str )
{
    if (str.length() > 10)
        // str.substr(0, 9) returns a substring
        // starting at index 0 with a length of 9 characters.
        return (str.substr( 0, 9 ) + ".");
	//creates a substring of spaces with 10-str.length lenght +str
    return std::string( 10 - str.length(), ' ' ) + str;
}

void PhoneBook::displayContacts() const
{
    std::cout << "---------------------------------------------" << std::endl;
    std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
    std::cout << "---------------------------------------------" << std::endl;

    for (int i = 0; i < _contactCount; ++i)
    {
        // std::setw(10) sets the width of the next output field to 10 chars.
        // If value is shorter than 10, it is right-aligned & padded with spaces.
        // It only affects the very next item sent to the output stream.
        std::cout << "|" << std::setw( 10 ) << i
                  << "|" << formatField( _contacts[i].getFirstName() )
                  << "|" << formatField( _contacts[i].getLastName() )
                  << "|" << formatField( _contacts[i].getNickname() )
                  << "|" << std::endl;
    }
    std::cout << "---------------------------------------------" << std::endl;
}

void PhoneBook::displayContactDetails(int i) const {
    if (i < 0 || i >= _contactCount) {
        std::cout << "Invalid index" << std::endl;
        return ;
    }
    std::cout << "First name: " << _contacts[i].getFirstName() << std::endl;
    std::cout << "Last name: " << _contacts[i].getLastName() << std::endl;
    std::cout << "Nickname: " << _contacts[i].getNickname() << std::endl;
    std::cout << "Phone number: " << _contacts[i].getPhoneNumber() << std::endl;
    std::cout << "Darkest secret: " << _contacts[i].getDarkestSecret() << std::endl;
}


bool PhoneBook::isAlphaString( const std::string &str)
{
    for (size_t i = 0; i < str.length(); ++i)
    {
        // std::isalpha requires int value in the range of unsigned char or EOF.
        // Casting ensures safe behavior for characters with negative values.
        if (!std::isalpha( static_cast<unsigned char>(str[i]) ) && str[i] != ' ')
            return false;
    }
    return true;
}

bool PhoneBook::isNumericString( const std::string &str)
{
    for (size_t i = 0; i < str.length(); ++i)
    {
        if (!std::isdigit( static_cast<unsigned char>(str[i]) ))
            return false;
    }
    return true;
}
