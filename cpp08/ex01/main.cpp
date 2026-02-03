/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeller- <ekeller-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 17:19:49 by ekeller-          #+#    #+#             */
/*   Updated: 2026/02/02 16:48:49 by ekeller-         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Span.hpp"
#include <iostream>

int main(){
    Span test(2);
    
    test.addNumber(2);
    test.addNumber(3);
    try {test.addNumber(4);}
    catch (std::exception &e) {std::cout << "Error: "<< e.what() << std::endl;}
    
    test.printNumbers();
}