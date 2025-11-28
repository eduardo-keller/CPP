/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeller-@student.42sp.org.br <ekeller-@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 14:44:32 by ekeller-          #+#    #+#             */
/*   Updated: 2025/11/27 18:39:33 by ekeller-@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
    if (this != &obj) {
        for (int i = 0; i < 100; ++i)
            ideas[i] = obj.ideas[i];
    }
    return *this;
}


const std::string& Brain::getIdeas(int index) const {
    static const std::string empty = "";
    if(index < 0 || index >= 100)
        return empty;
    return ideas[index];
}