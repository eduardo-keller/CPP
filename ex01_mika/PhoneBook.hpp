/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elianmik <elianmik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 10:45:53 by elianemika8       #+#    #+#             */
/*   Updated: 2025/07/01 14:17:45 by elianmik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include "utils.hpp"

class PhoneBook {
    private:
        Contact contacts[8];
        int contactCount;
        int index;

        static std::string formatField( const std::string &str );

    public:
        PhoneBook();
        void addContact();
        void displayContacts() const;
        void displayContactDetails( int i ) const;
};

#endif
