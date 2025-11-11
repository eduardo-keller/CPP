/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeller- <ekeller-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 12:23:54 by ekeller-          #+#    #+#             */
/*   Updated: 2025/11/11 12:14:12 by ekeller-         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

//notice that I did not use a constructor here. in this case the compiler declare a default
//constructor. in this case this is fine because the private strings will be populate with
//empty values and later populated with setContact. This is probably not the best practice.
class Contact {

    private:
        std::string _firstName;
        std::string _lastName;
        std::string _nickname;
        std::string _phoneNumber;
        std::string _darkSecret;
    
    public:
        void setContact( std::string fn, std::string ln,
            std::string nn, std::string pn, std::string ds);
        std::string getFirstName() const;
        std::string getLastName() const;
        std::string getNickname() const;
        std::string getPhoneNumber() const;
        std::string getDarkSecret() const;

};

#endif