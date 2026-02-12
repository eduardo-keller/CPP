/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeller- <ekeller-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 10:55:41 by ekeller-          #+#    #+#             */
/*   Updated: 2026/02/12 12:16:45 by ekeller-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <stack>
#include <exception>
#include <cctype>
#include <sstream>


RPN::RPN(){}

RPN::RPN(const RPN& other) : _operands(other._operands){}

RPN& RPN::operator=(const RPN& other)
{
	if (this != &other)
	{
		_operands = other._operands;
	}
	return *this;
}

RPN::~RPN(){}


long long RPN::evaluateExpression(std::string exp){
    std::istringstream iss(exp);
    std::string token;
    
    
    while (iss >> token) {
        if (token.size() != 1)
            throw std::runtime_error("Error: tokens must have 1 character");
        char c = token[0];
        
        if (c != '+' && c != '-' && c != '*' && c != '/' && !std::isdigit(c))
            throw std::runtime_error("Error: operator not suported");

        if (std::isdigit(c)) {
            _operands.push(static_cast<long long>(c - '0'));
            continue ;
        }
        if (_operands.size() < 2)
            throw std::runtime_error("Error: provide an inverted polish expression.");
        
        long long rightOperand = _operands.top();
        _operands.pop(); 
        long long leftOperand = _operands.top();
        _operands.pop();
        
        long long result = solveExpression(c, leftOperand, rightOperand);
        _operands.push(result); 
    }
    if (_operands.size() != 1)
        throw std::runtime_error("Error: provide an inverted polish expression.");
    return _operands.top();
    
}

long long RPN::solveExpression(char op, long long leftOperand, long long rightOperand){

        switch (op) {
            case '+':
                return (leftOperand + rightOperand);
            case '-':
                return (leftOperand - rightOperand);
            case '*':
                return (leftOperand * rightOperand);
            case '/':
                if (rightOperand == 0)
                    throw std::runtime_error("Error: division by zero");
                return (leftOperand / rightOperand);
            default:
                throw std::runtime_error("Error: operator not suported");
        }
    
}