/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeller- <ekeller-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 16:58:57 by ekeller-          #+#    #+#             */
/*   Updated: 2025/11/26 17:20:50 by ekeller-         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Cat.hpp"
#include "Brain.hpp"
#include <string>
#include <iostream>

//calling animal constructor here is not strictly necesssary
Cat::Cat() : Animal() {
    std::cout << "Cat default constructor called" << std::endl;
    type = "Cat";
    _brain = new Brain();
}

Cat::~Cat() {
    std::cout << "Cat default destructor called" << std::endl;
    delete _brain;
}


Cat::Cat(const Cat& obj) : Animal(obj) {
    std::cout << "Cat copy constructor called" << std::endl;
    _brain = new Brain(*obj._brain);
}

Cat& Cat::operator=(const Cat& obj){
    std::cout << "Cat assignment operator called" << std::endl;
    if(this != &obj)
    {
        type = obj.type;
        delete _brain;
        _brain = new Brain(*obj._brain);
    }
    return *this;
}

void Cat::makeSound() const {
    std::cout << "Meaw! Im a Cat" << std::endl;
}