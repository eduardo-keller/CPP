/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeller- <ekeller-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 16:27:27 by ekeller-          #+#    #+#             */
/*   Updated: 2025/11/25 11:47:49 by ekeller-         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(){
    ClapTrap c1("Dude");
    ScavTrap s1;
    ScavTrap s2("Truta");
    std::cout << std::endl;
    //check status of each object
    c1.getStatus();
    s1.getStatus();
    s2.getStatus();
    s2.guardGate();
    std::cout << std::endl;
    
    s2.attack("maluco");
    // s2.takeDamage(8);
    // s2.getStatus();
    // s2.beRepaired(3);
    // s2.getStatus();
    // s2.takeDamage(5);
    // s2.attack("maluco");
    std::cout << std::endl;
    
}