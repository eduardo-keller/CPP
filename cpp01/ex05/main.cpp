/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeller- <ekeller-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 18:29:37 by ekeller-          #+#    #+#             */
/*   Updated: 2025/11/14 16:18:17 by ekeller-         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Harl.hpp"
#include <string>
#include <iostream>

int main(){
    Harl test;
    std::string command;
    std::cout << "Running examples:" << std::endl;
    test.complain("DEBUG");
    std::cout << std::endl;
    test.complain("INFO");
    std::cout << std::endl;
    test.complain("WARNING");
    std::cout << std::endl;
    test.complain("ERROR");
    std::cout << std::endl;
    test.complain("x");
    std::cout << std::endl;
    std::cout << std::endl;
    
    std::cout << "Now test it if you want" << std::endl;
    std::cout << "Enter command: ";
    std::cin >> command;
    test.complain(command);

}