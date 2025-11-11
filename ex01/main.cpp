/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeller- <ekeller-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 11:21:43 by ekeller-          #+#    #+#             */
/*   Updated: 2025/11/11 11:42:52 by ekeller-         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <sstream> // std::istringstream
#include <iostream> // std::cout, std::cin
#include <string> // std::string

int main(void) {
    
    PhoneBook phonebook;
    std::string command;
    
    while(1) {
        std::cout << "Enter command (ADD, SEARCH or EXIT): ";
        std::getline(std::cin, command);
        if(command == "ADD")
            phonebook.addContact();
        else if(command == "SEARCH"){
            phonebook.displayContacts();
            std::cout << "Provide contact index: ";
            std::string indexStr;
            std::getline( std::cin, indexStr );
            //creates index that is a stream that can be read from( like an fd).
            std::istringstream index(indexStr);
            int i;
            //tries to store int strings in i. if its successfull, it will reach eof and
            //if will be true. example "123abc" will store 123 in i but the stream will not 
            //reach eof. 
            if (index >> i && index.eof())
                phonebook.displayContactDetails(i);
            else
                std::cout << "Invalid input." << std::endl;
        }
            
        else if(command == "EXIT")
            return 0;
        else
            std::cout << "Unknown command." << std::endl;
    }
}

