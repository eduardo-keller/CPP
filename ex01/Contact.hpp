/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeller- <ekeller-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 12:23:54 by ekeller-          #+#    #+#             */
/*   Updated: 2025/10/30 14:19:24 by ekeller-         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>

class Contact {

    public:
    Contact();
    ~Contact();

    std::string firstName;
    std::string lastName;
    std::string nickame;
    std::string phoneNumber;
    std::string secret;
};

#endif