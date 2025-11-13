/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeller- <ekeller-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 15:36:24 by ekeller-          #+#    #+#             */
/*   Updated: 2025/11/13 12:51:34 by ekeller-         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "HumanA.hpp"
#include "Weapon.hpp"
#include <string>
#include <iostream>

//
HumanA::HumanA(std::string setname, Weapon& weapon) :
    _name(setname), _weapon(weapon) {}

HumanA::~HumanA(){}

void HumanA::attack() const{
    std::cout << _name << " attacks with their " << _weapon.getType() << std::endl;
}