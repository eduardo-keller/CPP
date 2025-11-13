/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeller- <ekeller-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 13:01:01 by ekeller-          #+#    #+#             */
/*   Updated: 2025/11/13 15:43:41 by ekeller-         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "HumanB.hpp"
#include "Weapon.hpp"
#include <iostream>
#include <string>

HumanB::HumanB(std::string setName) : _name(setName), _weapon(NULL){}

HumanB::~HumanB(){}

void HumanB::attack() const{
    if (this->_weapon == NULL)
        std::cout << _name << " cannot attack without a weapon" << std::endl;
    else
        std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon &weapon){
    _weapon = &weapon;
}