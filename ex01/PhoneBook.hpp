/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeller-@student.42sp.org.br <ekeller-@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 11:14:15 by ekeller-          #+#    #+#             */
/*   Updated: 2025/11/05 17:53:00 by ekeller-@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook {
    private:
    Contact _contacts[8];
    int _contactCount;
    int _index;
    bool isNumericString(const std::string &str);
    bool isAlphaString(const std::string &str);
    static std::string formatField( const std::string &str );
    
    public:
    PhoneBook();
    void addContact();
    void displayContacts() const;

    
    int getIndex();
    
};

#endif