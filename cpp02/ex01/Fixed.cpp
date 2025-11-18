/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeller-@student.42sp.org.br <ekeller-@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 11:27:57 by ekeller-@st       #+#    #+#             */
/*   Updated: 2025/11/18 17:17:36 by ekeller-@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <string>
#include <iostream>
#include <cmath>

Fixed::Fixed() : _intFixedPoint(0) {
	std::cout << "Default constructor called" << std::endl;
};

Fixed::Fixed(const Fixed& obj) :  _intFixedPoint(obj._intFixedPoint){
	std::cout << "Copy constructor called" << std::endl;
}

Fixed::Fixed(const int value) {
	//transform int in fixed point
	//same as multiplying by value * 2^8(256);
	//example for int 10: 0000 0000 0000 1010
	//10 in fixed point:  0000 1010 0000 0000
	//so that the last 8 bits are left for the fractional part.
	_intFixedPoint = value << _intFractional;
}

Fixed::Fixed(const float value) {
	_intFixedPoint =  static_cast<int>(roundf(value * (1 << _intFractional)));
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

int Fixed::toInt( void ) const {
	return (_intFixedPoint >> _intFractional);
}


float Fixed::toFloat( void ) const {
	
}