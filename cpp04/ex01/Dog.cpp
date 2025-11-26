/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeller- <ekeller-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 17:09:26 by ekeller-          #+#    #+#             */
/*   Updated: 2025/11/26 18:30:54 by ekeller-         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Dog.hpp"
#include "Brain.hpp"
#include <string>
#include <iostream>

Dog::Dog() : Animal() {
    std::cout << "Dog default constructor called" << std::endl;
    type = "Dog";
    _brain = new Brain();
}

Dog::~Dog() {
    std::cout << "Dog default destructor called" << std::endl;
    delete _brain;
}


Dog::Dog(const Dog& obj) : Animal(obj) {
    std::cout << "Dog copy constructor called" << std::endl;
    _brain = new Brain(*obj._brain);
}

Dog& Dog::operator=(const Dog& obj){
    std::cout << "Dog assignment operator called" << std::endl;
    if(this != &obj)
    {
        type = obj.type;
        delete _brain;
        _brain = new Brain(*obj._brain);
    }
    return *this;
}

void Dog::makeSound() const {
    std::cout << "Au Au! Im a Dog" << std::endl;
}