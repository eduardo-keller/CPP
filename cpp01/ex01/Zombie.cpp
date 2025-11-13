/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeller- <ekeller-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 14:30:51 by ekeller-          #+#    #+#             */
/*   Updated: 2025/11/12 11:17:17 by ekeller-         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Zombie.hpp"
#include <iostream>
#include <string>

Zombie::Zombie() : name("unnamed"){
    std::cout << name << " constructor called"  << std::endl;
}

Zombie::~Zombie(){
    std::cout << name << " destructor called" << std::endl;
}

void Zombie::announce(void) {
    std::cout << "I'm " << name << "!" << std::endl;
}

void Zombie::setName(std::string set_name) {
    name = set_name; 
}