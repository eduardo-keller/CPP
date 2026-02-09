/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeller- <ekeller-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 12:51:54 by ekeller-          #+#    #+#             */
/*   Updated: 2026/02/09 18:31:45 by ekeller-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <string>
# include <iostream>
# include <map>

class BitcoinExchange {
    public:
        BitcoinExchange(); /////check!!!!!
        
        std::map<std::string, float> dB;
        
        void parseRates();
        void parseInput(char *argv);
};

#endif