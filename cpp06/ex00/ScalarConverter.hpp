/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeller- <ekeller-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 17:32:08 by ekeller-@st       #+#    #+#             */
/*   Updated: 2026/01/11 18:41:34 by ekeller-         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <string>

class ScalarConverter {
	//prevents instantiation;
	private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter& copy);
	ScalarConverter& operator=(const ScalarConverter& obj);
	~ScalarConverter();

	enum literalType {
		CHAR,
		INT,
		FLOAT,
		DOUBLE,
		PSEUDO_LITERAL,
		INVALID
	};
	
	static bool isInt(const std::string& str);
	static bool isFloat(const std::string& str);
	static bool isDouble(const std::string& str);
	static bool isChar(const std::string& str);
	static bool isPseudoLiteral(const std::string& str);
	static literalType detectType(const std::string& str);

	static void printPseudo(const std::string& str);
	static void printChar(double value);
	static void printInt(double value, bool impossible);
	static void printFloat(double value, bool impossible);
	static void printDouble(double value);

	public:
	static void convert(const std::string&  literal);
};

#endif