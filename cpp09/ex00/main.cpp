/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeller- <ekeller-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 16:35:51 by ekeller-          #+#    #+#             */
/*   Updated: 2026/02/12 13:00:04 by ekeller-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "BitcoinExchange.hpp"
#include <exception>

int main(int argc, char **argv){
    if (argc != 2) {
        std::cout << "Wrong number of arguments. Provide valid file" << std::endl;
        return 1;
    }
    BitcoinExchange btc;
    try {
        btc.parseRates();
        btc.parseInput(argv[1]);
    }
    catch(std::exception &e) {std::cerr << e.what() << std::endl;}
}