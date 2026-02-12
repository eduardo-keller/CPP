/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeller- <ekeller-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 17:48:10 by ekeller-          #+#    #+#             */
/*   Updated: 2026/02/12 12:17:11 by ekeller-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <stack>
# include <string>

class RPN {
    private:
        std::stack<long long> _operands;
        long long solveExpression(char op, long long leftOperand, long long rightOperand);
    
    public:
        RPN();
	    RPN(const RPN& other);
	    RPN& operator=(const RPN& other);
	    ~RPN();
    
        long long evaluateExpression(std::string exp);
};



#endif