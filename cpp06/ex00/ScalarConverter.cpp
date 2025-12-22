/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeller-@student.42sp.org.br <ekeller-@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 18:23:33 by ekeller-@st       #+#    #+#             */
/*   Updated: 2025/12/22 16:54:55 by ekeller-@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <cctype>
#include <string>

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &other) { (void)other; }

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other) {
    (void)other;
    return *this;
}

ScalarConverter::~ScalarConverter() {}



bool ScalarConverter::isInt(const std::string& str){
    unsigned long i = 0;
    
    if(str[i] == '-' || str[i] == '+')
        i++;
    for(; i < str.length(); i++) {
        if (!std::isdigit(str[i]))
            return false;
    }
    return true;
}

bool ScalarConverter::isFloat(const std::string& str){
    unsigned long i = 0;
    long          countDot = 0;
    
    if (str[str.length() - 1] != 'f')
        return false;
    if(str[i] == '-' || str[i] == '+')
        i++;
    for(; i < str.length() - 1; i++) {
        if (!std::isdigit(str[i]) && str[i] != '.')
            return false;
        if (str[i] == '.')
            countDot++;
    }
    if (countDot != 1)
        return false;
    return true;
}

bool ScalarConverter::isDouble(const std::string& str){
    unsigned long i = 0;
    long          countDot = 0;
    
    if(str[i] == '-' || str[i] == '+')
        i++;
    for(; i < str.length(); i++) {
        if (!std::isdigit(str[i]) && str[i] != '.')
            return false;
        if (str[i] == '.')
            countDot++;
    }
    if (countDot != 1)
        return false;
    return true;
}

bool ScalarConverter::isChar(const std::string& str){
    return (str.length() == 1 && !std::isdigit(str[0]) && std::isprint(str[0]));
}