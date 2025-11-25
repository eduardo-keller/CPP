/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeller- <ekeller-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 12:28:19 by ekeller-          #+#    #+#             */
/*   Updated: 2025/11/25 12:48:18 by ekeller-         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Animal.hpp"
#include <string>
#include <iostream>

Animal::Animal() : type("animal"){
    std::cout << "Animal default constructor called" << std::endl;
}

Animal::~Animal() {
    std::cout << "Animal default destructor called" << std::endl;
}

Animal::Animal(const Animal& obj) {
    std::cout << "Animal copy constructor called" << std::endl;
}