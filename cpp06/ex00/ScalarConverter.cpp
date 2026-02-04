/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeller- <ekeller-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 18:23:33 by ekeller-@st       #+#    #+#             */
/*   Updated: 2026/01/20 15:39:40 by ekeller-         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "ScalarConverter.hpp"
#include <cctype>
#include <string>
#include <iostream>
#include <cstdlib>
#include <limits> 
#include <iomanip>

//static_cast is used for compile-time conversions. it computes a new value from the original value
//for example, if you convert 42.9 to int will give 42, which is a completely different bit
//pattern 

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
    return (str.length() == 1 && !std::isdigit(str[0])); 
}

bool ScalarConverter::isPseudoLiteral(const std::string& literal) {
	return literal == "nan" || literal == "nanf" ||
		   literal == "+inf" || literal == "-inf" ||
		   literal == "+inff" || literal == "-inff" ||
		   literal == "inf" || literal == "inff";
}

void ScalarConverter::convert(const std::string& literal) {
    double value = 0; 
    bool intImpossible = false;
    bool floatImpossible = false;

    if (literal.empty())
        return ;
    literalType type = detectType(literal);


    switch (type) {
        case CHAR:
            value = static_cast<double>(literal[0]);
            break;
        case INT:
            value = std::strtod(literal.c_str(), NULL);
            if (value > std::numeric_limits<int>::max() || value < std::numeric_limits<int>::min())
                intImpossible = true;
            if (value > std::numeric_limits<float>::max() || value < -std::numeric_limits<float>::max())
                floatImpossible = true;
            break;
        case FLOAT:
            value = std::strtod(literal.c_str(), NULL);
            //for min float needs to be -max() because min gives the smallest positive valu in c++
            if (value > std::numeric_limits<float>::max() || value < -std::numeric_limits<float>::max())
                floatImpossible = true;
            break;
        case DOUBLE:
            value = std::strtod(literal.c_str(), NULL);
            break;
        case PSEUDO_LITERAL:
            printPseudo(literal);
            return ;
        case INVALID:
            std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: impossible" << std::endl;
			std::cout << "double: impossible" << std::endl;
            return ;

    }
    printChar(value);
    printInt(value, intImpossible);
    printFloat(value, floatImpossible);
    printDouble(value);
}

void ScalarConverter::printChar(double value){
    std::cout << "char: ";
    if (value < 32 || value > 126)
		std::cout << "Non displayable" << std::endl;
    else
        std::cout << "'" << static_cast<char>(value) << "'" << std::endl;
}

void ScalarConverter::printInt(double value, bool intImpossible) {
    std::cout << "int: ";
    if (intImpossible)
        std::cout <<  "impossible" << std::endl;
    else
        std::cout << static_cast<int>(value) << std::endl;
}

void ScalarConverter::printFloat(double value, bool floatImpossible) {
    std::cout << "float: ";
    if (floatImpossible)
        std::cout <<  "impossible" << std::endl;
    else
        std::cout << std::fixed << std::setprecision(1) << static_cast<float>(value) << "f" << std::endl;
}

void ScalarConverter::printDouble(double value) {
    std::cout << std::fixed << std::setprecision(1) << "double: " << static_cast<double>(value) <<  std::endl;
}



ScalarConverter::literalType ScalarConverter::detectType(const std::string& str) {
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