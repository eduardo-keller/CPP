/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeller- <ekeller-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 11:56:16 by ekeller-          #+#    #+#             */
/*   Updated: 2025/11/12 14:37:05 by ekeller-         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include <string>
#include <iostream>

// a reference is constant and must be initialized at the same time is declared.
// its an alias for an existent variable. it cannot be null. it cannot change and
//point to another value
int main(){
	
	std::string str = "HI THIS IS BRAIN";
	std::string* stringPTR = &str;
	std::string& stringREF = str;

	std::cout << "String Adress: " << &str << std::endl;
	std::cout << "Pointer address: " << stringPTR << std::endl;
	std::cout << "Reference address: "<< &stringREF << std::endl;

	std::cout << std::endl;

	std::cout << "String value: "<< str << std::endl;
	std::cout << "Pointer value: "<< *stringPTR << std::endl;
	std::cout << "Reference value: "<< stringREF << std::endl;
	
}
