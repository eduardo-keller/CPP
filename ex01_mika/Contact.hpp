/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elianmik <elianmik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 10:44:48 by elianemika8       #+#    #+#             */
/*   Updated: 2025/07/01 14:15:27 by elianmik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// This .hpp file is used for declarations only.
// Here, u define the structure of your class, including:

// - Class declaration
// - Declaration of member variables (usually marked as private)
// - Declaration of public methods (functions accessible from outside the class)
// - Include guards (#ifndef, #define, #endif) to prevent multiple inclusions
// - All libraries needed

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <cctype>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

class Contact {
    private:
        std::string firstName;
        std::string lastName;
        std::string nickname;
        std::string phoneNumber;
        std::string darkestSecret;

    public:
        void setContact( std::string fn, std::string ln,
            std::string nn, std::string pn, std::string ds );

        std::string getFirstName() const;
        std::string getLastName() const;
        std::string getNickname() const;
        std::string getPhoneNumber() const;
        std::string getDarkestSecret() const;
};

#endif
