/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeller- <ekeller-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 16:27:27 by ekeller-          #+#    #+#             */
/*   Updated: 2025/11/25 11:51:41 by ekeller-         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "ClapTrap.hpp"
#include "FragTrap.hpp"

int main(){
    FragTrap f2("Truta");
    FragTrap f3(f2);
    
    std::cout << std::endl;
    //check status of each object
    f2.getStatus();
    f3.getStatus();
    
    f2.highFivesGuys();
    std::cout << std::endl;
    f2.attack("maluco");
    f2.takeDamage(10);
    f2.getStatus();
    f2.beRepaired(10);
    f2.getStatus();
    f2.takeDamage(100);
    f2.attack("maluco");
    std::cout << std::endl;
    
}