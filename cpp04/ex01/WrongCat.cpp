/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeller- <ekeller-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 12:46:39 by ekeller-          #+#    #+#             */
/*   Updated: 2025/11/26 12:50:06 by ekeller-         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "WrongCat.hpp"
#include <string>
#include <iostream>

//calling animal constructor here is not strictly necesssary
WrongCat::WrongCat() : WrongAnimal() {
    std::cout << "WrongCat default constructor called" << std::endl;
    type = "WrongCat";
}

WrongCat::~WrongCat() {
    std::cout << "WrongCat default destructor called" << std::endl;
}

//calling animal copy constructor here is strictly necesssary, otherwise the copied base object
//would not be a copy of the base object
WrongCat::WrongCat(const WrongCat& obj) : WrongAnimal(obj) {
    std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& obj){
    if(this != &obj)
        WrongAnimal::operator=(obj);
    return *this;
}

void WrongCat::makeSound() const {
    std::cout << "Meaw! Im a WrongCat" << std::endl;
}