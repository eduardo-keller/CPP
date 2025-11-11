/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeller- <ekeller-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 14:30:51 by ekeller-          #+#    #+#             */
/*   Updated: 2025/11/11 16:04:08 by ekeller-         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Zombie.hpp"
#include <iostream>
#include <string>

Zombie::Zombie(std::string name) : name(name)
{
    std::cout << name << " constructor called"  << std::endl;
}

Zombie::~Zombie(){
    std::cout << name << " destructor called" << std::endl;
}

void Zombie::announce(void)
{
    std::cout << name << ": BraiiiiiiinnnzzzZ..."  << std::endl;
}