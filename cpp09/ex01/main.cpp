/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeller- <ekeller-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 18:11:53 by ekeller-          #+#    #+#             */
/*   Updated: 2026/02/12 12:04:54 by ekeller-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>
#include <string>
#include "RPN.hpp"

int main(int argc, char **argv) {
    if (argc != 2)
    {
		std::cerr << "Error: provide one argument" << std::endl;
		return 1;
	}
    try
	{
		RPN rpn;
		long result = rpn.evaluateExpression(argv[1]);
		std::cout << result << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}

	return 0;
}
