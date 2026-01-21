/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeller- <ekeller-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 12:55:00 by ekeller-          #+#    #+#             */
/*   Updated: 2026/01/20 15:11:45 by ekeller-         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <stdint.h> 
# include "Data.hpp"

class Serializer{
  	private:
	Serializer();
	Serializer(const Serializer& copy);
	Serializer& operator=(const Serializer& obj);
	~Serializer();  
    
    public:
    static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw);

};

#endif