/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeller- <ekeller-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 15:00:29 by ekeller-          #+#    #+#             */
/*   Updated: 2025/11/13 12:50:40 by ekeller-         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include <string>
#include "Weapon.hpp"

Weapon::Weapon(std::string type) : _type(type){};

Weapon::~Weapon() {};

void Weapon::setType(std::string new_type){
    _type = new_type;
}

const std::string& Weapon::getType() const{
    return _type;
}
