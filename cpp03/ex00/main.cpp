/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeller- <ekeller-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 16:27:27 by ekeller-          #+#    #+#             */
/*   Updated: 2025/11/24 16:50:31 by ekeller-         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "ClapTrap.hpp"

int main(){
    ClapTrap test("Dude");

    test.getStatus();
    test.attack("maluco");
    test.takeDamage(8);
    test.getStatus();
    test.beRepaired(3);
    test.getStatus();
    test.takeDamage(5);
    test.attack("maluco");
    
}