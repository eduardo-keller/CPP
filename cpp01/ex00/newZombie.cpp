/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeller- <ekeller-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 15:48:30 by ekeller-          #+#    #+#             */
/*   Updated: 2025/11/11 15:58:17 by ekeller-         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Zombie.hpp"

Zombie* newZombie( std::string name ) {
    Zombie *heapzombie = new Zombie(name);
    
    return heapzombie;
}