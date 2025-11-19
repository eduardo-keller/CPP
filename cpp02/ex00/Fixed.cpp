/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeller-@student.42sp.org.br <ekeller-@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 11:27:57 by ekeller-@st       #+#    #+#             */
/*   Updated: 2025/11/19 11:40:17 by ekeller-@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <string>
#include <iostream>

Fixed::Fixed() : _intFixedPoint(0) {
	std::cout << "Default constructor called" << std::endl;
};

Fixed::Fixed(const Fixed& obj) :  _intFixedPoint(obj._intFixedPoint){
	std::cout << "Copy constructor called" << std::endl;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
};

Fixed& Fixed::operator=(const Fixed& obj){
	std::cout << "Assignment operator called" << std::endl;
	//standard check. important if the class has dynamic memory allocation.
	if (this != &obj)
		this->_intFixedPoint = obj._intFixedPoint;
	return *this;
}

int Fixed::getRawBits() const {
	return _intFixedPoint;
}

void Fixed::setRawBits(int const raw) {
	_intFixedPoint = raw;
}
