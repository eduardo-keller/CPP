/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeller- <ekeller-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 16:44:29 by ekeller-          #+#    #+#             */
/*   Updated: 2025/11/11 17:30:46 by ekeller-         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Zombie.hpp"
#include <string>

Zombie* zombieHorde( int N, std::string name ) {
    Zombie *horde = new Zombie[N];

    for(int i = 0; i < N; i++) {
        horde[i].setName(name);
    }

    return horde;
}