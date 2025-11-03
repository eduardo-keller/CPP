/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeller-@student.42sp.org.br <ekeller-@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 12:23:54 by ekeller-          #+#    #+#             */
/*   Updated: 2025/11/03 16:51:12 by ekeller-@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>

class Contact {

    private:
    std::string firstName;
    std::string lastName;
    std::string nickame;
    std::string phoneNumber;
    std::string secret;
    
    public:
    Contact();
    ~Contact();


};

#endif