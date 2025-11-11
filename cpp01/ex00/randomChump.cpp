/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeller- <ekeller-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 16:06:05 by ekeller-          #+#    #+#             */
/*   Updated: 2025/11/11 16:10:23 by ekeller-         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Zombie.hpp"

void randomChump( std::string name ) {
    Zombie stack_zombie = Zombie(name);
    stack_zombie.announce();
    
 }