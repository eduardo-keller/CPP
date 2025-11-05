/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeller-@student.42sp.org.br <ekeller-@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 11:21:43 by ekeller-          #+#    #+#             */
/*   Updated: 2025/11/05 18:07:26 by ekeller-@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

int main(void) {
    
    PhoneBook phonebook;
    std::string command;
    
    while(1) {
        std::cout << "Enter command (ADD, SEARCH or EXIT): ";
        std::getline(std::cin, command);
        //std::cout << command << std::endl;
        //std::cout << phonebook.getIndex() << std::endl;
        if(command == "ADD")
            phonebook.addContact();
        else if(command == "SEARCH"){
            phonebook.displayContacts();
            std::cout << "Provide contact index: ";
            std::string indexStr;
            std::getline( std::cin, indexStr );            
        }
            
        else if(command == "EXIT")
            return 0;
        else
            std::cout << "Unknown command." << std::endl;
    }
    
}

