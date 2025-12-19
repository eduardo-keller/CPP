/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeller-@student.42sp.org.br <ekeller-@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 15:41:33 by ekeller-@st       #+#    #+#             */
/*   Updated: 2025/12/19 16:17:35 by ekeller-@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <string>
#include <iostream>

void	testIsInt(){
	
	std::string test[] = {"ab", "a", "1a", "a1", "!", ".", "<", "1.", "1.0", "1", "12", "222222222222222222222222222222222222222222222222222222222222222222222222222", ""};
	for(int i = 0; !test[i].empty(); i++){
		//std::cout << test[i] << " ";
		std::cout << ScalarConverter::isInt(test[i]) << " ";
	}
		
	
}




int main(){
	testIsInt();
	
}