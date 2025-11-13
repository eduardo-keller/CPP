/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeller- <ekeller-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 15:08:53 by ekeller-          #+#    #+#             */
/*   Updated: 2025/11/13 15:17:37 by ekeller-         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"
#include <iostream>

int main(){
    {
    Weapon club("crude spiked club");
    HumanA bob("bob", club);
    bob.attack();
    club.setType("some other type of club");
    bob.attack();
    }
    {
    Weapon club("crude spiked club");
    HumanB jim("Jim");
    jim.attack();
    jim.setWeapon(club);
    jim.attack();
    club.setType("some other type of club");
    jim.attack();
    }
    
}