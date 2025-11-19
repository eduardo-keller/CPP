/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeller-@student.42sp.org.br <ekeller-@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 11:28:03 by ekeller-@st       #+#    #+#             */
/*   Updated: 2025/11/19 15:52:08 by ekeller-@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

int main( void ) {
Fixed a;
Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
std::cout << a << std::endl;
std::cout << ++a << std::endl;
std::cout << a << std::endl;
std::cout << a++ << std::endl;
std::cout << a << std::endl;
std::cout << b << std::endl;
std::cout << Fixed::max( a, b ) << std::endl;
return 0;
}

// int main (void) {
// 	Fixed a(2);
// 	Fixed b(3);
// 	Fixed c(3.1f);
// 	Fixed d;

// 	std::cout << (a > b) << std::endl;
// 	std::cout << (b > a) << std::endl;
// 	std::cout << (b > c) << std::endl;
// 	std::cout << (a / d) << std::endl;
// 	std::cout << (a == b) << std::endl;
// 	std::cout << (a != b) << std::endl;

// 	std::cout << (b - a) << std::endl;
// 	std::cout << (b + a) << std::endl;
// 	std::cout << Fixed::max( a, b ) << std::endl;
// 	std::cout << Fixed::min( a, b ) << std::endl;
	
// }