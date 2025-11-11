/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeller- <ekeller-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 14:35:18 by ekeller-          #+#    #+#             */
/*   Updated: 2025/11/11 16:14:50 by ekeller-         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Zombie.hpp"
#include <iostream>

int main(){
    std::cout << std::endl;
    
    Zombie *heapZombie = newZombie("Heap Zombie");
    heapZombie->announce();
    delete heapZombie;
    
    std::cout << std::endl;
    randomChump("Stack Zombie");
    std::cout << std::endl;
}