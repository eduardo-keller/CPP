/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeller- <ekeller-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 18:13:11 by ekeller-          #+#    #+#             */
/*   Updated: 2026/01/22 12:50:18 by ekeller-         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "whatever.hpp"
#include <iostream>


int main(){
    int a_int = 2, b_int = 3;
    float a_float=2.2, b_float=3.3;
    std::string a_string = "chaine1", b_string = "chaine2";
    
    std::cout << "SWAP TEST: " << std::endl;
    swap(a_int, b_int);
    swap(a_float, b_float);
    swap(a_string, b_string);
    std::cout << "a_int = " << a_int << ", b_int = " << b_int << std::endl;
    std::cout << "a_float = " << a_float << ", b_float = " << b_float << std::endl;
    std::cout << "a_string = " << a_string << ", b_string = " << b_string << std::endl;

    std::cout << std::endl << "MIN/MAX TEST: " << std::endl;
    std::cout << "int: min( a, b ) = " << min( a_int, b_int ) << std::endl;
    std::cout << "int: max( a, b ) = " << max( a_int, b_int ) << std::endl;
    std::cout << "float: min( a, b ) = " << min( a_float, b_float ) << std::endl;
    std::cout << "float: max( a, b ) = " << max( a_float, b_float ) << std::endl;
    std::cout << "string: min( a, b ) = " << min( a_string, b_string ) << std::endl;
    std::cout << "string: max( a, b ) = " << max( a_string, b_string ) << std::endl;

}