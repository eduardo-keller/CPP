/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeller- <ekeller-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 12:50:16 by ekeller-          #+#    #+#             */
/*   Updated: 2026/01/26 15:35:11 by ekeller-         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "iter.hpp"
#include <cstring>
#include <iostream>


void toUpper(char &c){
    if (c >= 'a' && c <= 'z')
        c -= 32;
}

template <typename T>
void print(T const &elem)
{
	std::cout << elem << " ";
}


void increment(int &i){
    i++;
}



int main(void){
   char array_char[] = {'a', 'b', '4'};
    int array_int[] = {1, 2 , 3, 4};
    std::string array_str[] = {"hello", "world"};
    
    std::cout << "---TEST CHAR---" << std::endl;
    std::cout << "Initial array: ";
    iter(array_char, sizeof(array_char)/ sizeof(array_char[0]), print);;
    iter(array_char, sizeof(array_char)/ sizeof(array_char[0]), toUpper);
    std::cout << std::endl;
    std::cout << "Array after toUpper: ";
    iter(array_char, sizeof(array_char)/ sizeof(array_char[0]), print);
    std::cout << std::endl;

    std::cout << "---TEST INT---" << std::endl;
    std::cout << "Initial array: ";
    iter(array_int, sizeof(array_int)/sizeof(array_int[0]), print);
    std::cout << std::endl;
    iter(array_int, sizeof(array_int)/sizeof(array_int[0]), increment);
    std::cout << "Array after increment: ";
    iter(array_int, sizeof(array_int)/sizeof(array_int[0]), print);
    std::cout << std::endl;
    
    std::cout << "---TEST STRING---" << std::endl;
	size_t strLen = sizeof(array_str) / sizeof(array_str[0]);

	std::cout << "String array: ";
	::iter(array_str, strLen, print<std::string>);
	std::cout << std::endl;
}