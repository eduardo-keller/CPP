/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeller-@student.42sp.org.br <ekeller-@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 11:27:57 by ekeller-@st       #+#    #+#             */
/*   Updated: 2025/11/19 15:31:49 by ekeller-@st      ###   ########.fr       */
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

//transform int in fixed point
//same as multiplying by value * 2^8(256);
//example for int 10: 0000 0000 0000 1010
//10 in fixed point:  0000 1010 0000 0000
//so that the last 8 bits are left for the fractional part.
Fixed::Fixed(const int value) {
	std::cout << "Int constructor called" << std::endl;
	_intFixedPoint = value << _fractional;
}

//transform float in fixed point
// 1 << 8 is 256
//need to use this syntax (1 << _fractional) because the << operand
//cannot be used on floats.
Fixed::Fixed(const float value) {
	std::cout << "Float constructor called" << std::endl;
	_intFixedPoint =  static_cast<int>(roundf(value * (1 << _fractional)));
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
};

Fixed& Fixed::operator=(const Fixed& obj){
	std::cout << "Copy assignment operator called" << std::endl;
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
	return (_intFixedPoint >> _fractional);
}


float Fixed::toFloat( void ) const {
	return static_cast<float>(_intFixedPoint) / (1 << _fractional);
}


std::ostream& operator<<(std::ostream& out, const Fixed& obj) {
	out <<  obj.toFloat();
	return out;
}


bool Fixed::operator>(const Fixed& other) const { return _intFixedPoint > other._intFixedPoint; }
bool Fixed::operator<(const Fixed& other) const { return _intFixedPoint < other._intFixedPoint; }
bool Fixed::operator>=(const Fixed& other) const { return _intFixedPoint >= other._intFixedPoint; }
bool Fixed::operator<=(const Fixed& other) const { return _intFixedPoint <= other._intFixedPoint; }
bool Fixed::operator==(const Fixed& other) const { return _intFixedPoint == other._intFixedPoint; }
bool Fixed::operator!=(const Fixed& other) const { return _intFixedPoint != other._intFixedPoint; }


Fixed Fixed::operator+(const Fixed& other) const 
{
    return Fixed(this->toFloat() + other.toFloat());
}
Fixed Fixed::operator-(const Fixed& other) const 
{
    return Fixed(this->toFloat() - other.toFloat());
}
Fixed Fixed::operator*(const Fixed& other) const 
{
    return Fixed(this->toFloat() * other.toFloat());
}
Fixed Fixed::operator/(const Fixed& other) const 
{
    if (other.getRawBits() == 0)
	{
		std::cout << "NOOOOOOOOOOOOOOOOOOO!!!!!!!!!!!!!!!!!" << std::endl;
		return Fixed();
	}
	return Fixed(this->toFloat() / other.toFloat());
}

//pré increment. x=5; a = ++x; a=6
Fixed& Fixed::operator++()
{
	_intFixedPoint++;
	return *this;
}

//pós increment. x=5; a = x++; a=5
Fixed Fixed::operator++(int)
{
	Fixed temp(*this);
	_intFixedPoint++;
	return temp;
}

Fixed& Fixed::operator--()
{
	_intFixedPoint--;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed temp(*this);
	_intFixedPoint--;
	return temp;
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	return (a < b) ? a : b;
}
const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	return (a < b) ? a : b;
}
Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	return (a > b) ? a : b;
}
const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	return (a > b) ? a : b;
}