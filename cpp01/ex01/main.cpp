/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeller- <ekeller-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 14:35:18 by ekeller-          #+#    #+#             */
/*   Updated: 2025/11/12 12:01:34 by ekeller-         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Zombie.hpp"

int main(void){
int size = 3;
    
    Zombie *horde = zombieHorde(size, "Truta");
    
    for(int i = 0; i < size; i++)
        horde[i].announce();
    delete [] horde;
}