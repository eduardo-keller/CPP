/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeller- <ekeller-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 12:28:19 by ekeller-          #+#    #+#             */
/*   Updated: 2025/11/26 12:33:26 by ekeller-         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Animal.hpp"
#include <string>
#include <iostream>

Animal::Animal() : type("generic animal"){
    std::cout << "Animal default constructor called" << std::endl;
}

Animal::~Animal() {
    std::cout << "Animal default destructor called" << std::endl;
}

Animal::Animal(const Animal& obj) {
    std::cout << "Animal copy constructor called" << std::endl;
    this->type = obj.type;
}

Animal& Animal::operator=(const Animal& obj){
    if(this != &obj)
        this->type = obj.type;
    return *this;
}

void Animal::makeSound() const {
    std::cout << "Generic animal sound" << std::endl;
}
const std::string& Animal::getType() const {
    return type;
}