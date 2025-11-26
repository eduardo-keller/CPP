/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeller- <ekeller-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 14:44:32 by ekeller-          #+#    #+#             */
/*   Updated: 2025/11/26 17:23:17 by ekeller-         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Brain.hpp"
#include <string>
#include <iostream>

Brain::Brain(){
    std::cout << "Brain default constructor called" << std::endl;
}

Brain::~Brain() {
    std::cout << "Brain default destructor called" << std::endl;
}

Brain::Brain(const Brain& obj) {
    std::cout << "Brain copy constructor called" << std::endl;
    for (int i = 0; i < 100; i++)
        ideas[i] = obj.ideas[i];
}

Brain& Brain::operator=(const Brain& obj){
    if(this != &obj)
        Brain::operator=(obj);
    return *this;
}


const std::string& Brain::getIdeas(int index) const {
    if(index < 0 || index >= 100)
        return NULL;
    return ideas[index];
}