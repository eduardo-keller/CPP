/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elianmik <elianmik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 13:53:40 by elianmik          #+#    #+#             */
/*   Updated: 2025/07/02 08:05:00 by elianmik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"

bool isAlphaString( const std::string& str )
{
    for (size_t i = 0; i < str.length(); ++i)
    {
        // std::isalpha requires int value in the range of unsigned char or EOF.
        // Casting ensures safe behavior for characters with negative values.
        if (!std::isalpha( static_cast<unsigned char>(str[i]) ) && str[i] != ' ')
            return false;
    }
    return true;
}

bool isNumericString( const std::string& str )
{
    for (size_t i = 0; i < str.length(); ++i)
    {
        if (!std::isdigit( static_cast<unsigned char>(str[i]) ))
            return false;
    }
    return true;
}
