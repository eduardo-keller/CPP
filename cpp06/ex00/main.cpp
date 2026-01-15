/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeller- <ekeller-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 15:41:33 by ekeller-@st       #+#    #+#             */
/*   Updated: 2026/01/11 18:40:45 by ekeller-         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "ScalarConverter.hpp"
#include <string>
#include <iostream>
#include <cmath>
#include <limits>


int main(int argc, char **argv){
	if (argc != 2)
	{
		std::cout << "Wrong number of arguments" << std::endl <<   "Usage: ./cast <string literal>" << std::endl;
		return 1;
	}
	ScalarConverter::convert(argv[1]);
	return 0;
}
