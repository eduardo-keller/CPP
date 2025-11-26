/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeller- <ekeller-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 12:38:26 by ekeller-          #+#    #+#             */
/*   Updated: 2025/11/26 12:39:14 by ekeller-         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "WrongAnimal.hpp"
#include <string>
#include <iostream>

WrongAnimal::WrongAnimal() : type("generic WrongAnimal"){
    std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal() {
    std::cout << "WrongAnimal default destructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& obj) {
    std::cout << "WrongAnimal copy constructor called" << std::endl;
    this->type = obj.type;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& obj){
    if(this != &obj)
        this->type = obj.type;
    return *this;
}

void WrongAnimal::makeSound() const {
    std::cout << "Generic WrongAnimal sound" << std::endl;
}
const std::string& WrongAnimal::getType() const {
    return type;
}