/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeller- <ekeller-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 18:23:33 by ekeller-@st       #+#    #+#             */
/*   Updated: 2026/01/11 19:07:27 by ekeller-         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "ScalarConverter.hpp"
#include <cctype>
#include <string>
#include <iostream>

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
    return (str.length() == 1 && !std::isdigit(str[0])); // && std::isprint(str[0]? better to include before printing?
}

bool ScalarConverter::isPseudoLiteral(const std::string& literal) {
	return literal == "nan" || literal == "nanf" ||
		   literal == "+inf" || literal == "-inf" ||
		   literal == "+inff" || literal == "-inff" ||
		   literal == "inf" || literal == "inff";
}

void ScalarConverter::convert(const std::string& literal) {
    
    if (literal.empty())
        return ;
    literalType type = detectType(literal);
    if (isPseudoLiteral(literal)) {
        printPseudo(literal);
        return ;
    }


    
}

literalType ScalarConverter::detectType(const std::string& str) {
    if (isChar(str))
        return CHAR;
    else if (isInt(str))
        return INT;
    else if (isFloat(str))
        return FLOAT;
    else if (isDouble(str))
        return DOUBLE;
    else if (isPseudoLiteral(str))
        return PSEUDO_LITERAL;    
    else
        return INVALID;
}

void ScalarConverter::printPseudo(const std::string& str) {
    if (str == "nan" || str == "nanf" ) {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
    }
    else if (str == "+inf" || str == "+inff" || str == "inf" || str == "inff") {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: +inff" << std::endl;
        std::cout << "double: +inf" << std::endl;
    }
    else if (str == "-inf" || str == "-inff") {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: -inff" << std::endl;
        std::cout << "double: -inf" << std::endl;
    }
}