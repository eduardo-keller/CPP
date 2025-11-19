/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeller-@student.42sp.org.br <ekeller-@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 11:28:03 by ekeller-@st       #+#    #+#             */
/*   Updated: 2025/11/19 11:30:06 by ekeller-@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

int main() {
	Fixed a;
	Fixed b(a);
	Fixed c;
	
	a.setRawBits(42);
	std::cout << "fixed point a: " << a.getRawBits() << std::endl;
	std::cout << "fixed point b: " << b.getRawBits() << std::endl;
	std::cout << "fixed point c: " << c.getRawBits() << std::endl;
	b.setRawBits(33);
	c = b;
	std::cout << "fixed point a: " << a.getRawBits() << std::endl;
	std::cout << "fixed point b: " << b.getRawBits() << std::endl;
	std::cout << "fixed point c: " << c.getRawBits() << std::endl;
	
}