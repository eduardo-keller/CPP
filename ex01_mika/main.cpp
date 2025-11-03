/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elianmik <elianmik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 10:46:25 by elianemika8       #+#    #+#             */
/*   Updated: 2025/07/01 14:15:47 by elianmik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main()
{
    PhoneBook phoneBook;
    std::string command;

    std::cout << "Welcome to the 80s PhoneBook!" << std::endl;

    while (true)
    {
        std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
        std::getline( std::cin, command );

        if (std::cin.eof())
            break;

        if (command == "ADD")
            phoneBook.addContact();
        else if (command == "SEARCH")
        {
            phoneBook.displayContacts();
            std::cout << "Enter index: ";
            std::string indexStr;
            std::getline( std::cin, indexStr );
            
            // Creates an input stream based on the string indexStr:
            std::istringstream index( indexStr );
            int i;
            
            // Tries to extract an int from the string
            // and store it in the variable i:
            if (index >> i && index.eof())
                phoneBook.displayContactDetails(i);
            else
                std::cout << "Invalid input." << std::endl;
        }
        else if (command == "EXIT")
        {
            std::cout << "Exiting... All contacts lost!" << std::endl;
            break;
        }
        else
            std::cout << "Unknown command." << std::endl;
    }
    return 0;
}
