/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeller- <ekeller-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 17:29:49 by ekeller-          #+#    #+#             */
/*   Updated: 2026/01/09 17:30:10 by ekeller-         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "ScalarConverter.hpp"
#include <string>
#include <iostream>

void	testIsInt(){
	std::string test[] = {"ab", "a", "1a", "a1", "!", ".", "<", "1.", "1.0",
		"1", "12", "2147483700", "+12", "-42", ""};
	for(int i = 0; !test[i].empty(); i++){
		//std::cout << test[i] << " ";
		std::cout << ScalarConverter::isInt(test[i]) << " ";
	}
}

void	testIsFloat(){
	std::string test[] = {"ab", "a", "1.a", "a1.0", "!", "<", "1f", "1.0.0f", ".02f", "1.f",
		"1.102f", "2147483700.2f", "+12.1f", "-42.1f", "1.0f", ""};

	for(int i = 0; !test[i].empty(); i++){
		//std::cout << test[i] << " ";
		if(i == 8)
			std::cout << "should be true: ";
		std::cout << ScalarConverter::isFloat(test[i]) << " ";
	}
}

void	testIsDouble(){
	std::string test[] = {"ab", "a", "1.a", "a1.0", "!", "1.0.0", "1.0f", "1.0.0f", ".02", "1.",
		"1.102", "2147483700.2", "+12.1", "-42.1", "1.0", ""};

	for(int i = 0; !test[i].empty(); i++){
		//std::cout << test[i] << " ";
		if(i == 8)
			std::cout << "should be true: ";
		std::cout << ScalarConverter::isDouble(test[i]) << " ";
	}
}

void	testIsChar(){
	std::string test[] = {"ab", "1a", "a1", "1.", "1.0", "!", ".", "<", "a", ""};
	for(int i = 0; !test[i].empty(); i++){
		if(i == 5)
			std::cout << "should be true: ";
		std::cout << ScalarConverter::isChar(test[i]) << " ";
	}
}





int main(){
	
	std::cout << "Test Int: \n";
	testIsInt();
	std::cout << "\nTest Float: \n";
	testIsFloat();
	std::cout << "\nTest Double: \n";
	testIsDouble();
	std::cout << "\nTest Char: \n";
	testIsChar();
	
}