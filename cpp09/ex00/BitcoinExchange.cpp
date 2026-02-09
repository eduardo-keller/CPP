/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeller- <ekeller-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 16:53:54 by ekeller-          #+#    #+#             */
/*   Updated: 2026/02/09 18:31:51 by ekeller-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <fstream>
#include <cstdlib>

BitcoinExchange::BitcoinExchange(){}


void BitcoinExchange::parseRates(){
    std::ifstream file("data.csv");
    if (!file) {
        std::cerr << "Error: Could not open the file." << std::endl;
        return ;
    }
    std::string line;
    //discard comlumn names
    std::getline(file, line);
    std::string date;
    std::string rate;
    while (std::getline(file, line)){
        date = line.substr(0, 10);
        rate = line.substr(11, line.size());
        dB[date] = std::strtof(rate.c_str(), NULL);}
}


void BitcoinExchange::parseInput(char * argv) {
    std::ifstream file(argv);
    if (!file) {
        std::cerr << "Error: Could not open the file." << std::endl;
        return ;
    }
}