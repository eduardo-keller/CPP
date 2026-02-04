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

// int main(){
//     Span test(10);
//     std::vector<int> range;

//     for(int i = 2; i < 10; i++)
//         range.push_back(i);
    
//     test.addNumber(12);
//     test.addNumber(13);
//     test.addRange(range.begin(), range.end());
//     test.printNumbers();
//     test.shortestSpan();
    
//     try {test.addNumber(10);}
//     catch (std::exception &e) {std::cout << "Error: "<< e.what() << std::endl;}
    
// }

int main()
{
Span sp = Span(5);
sp.addNumber(6);
sp.addNumber(3);
sp.addNumber(17);
sp.addNumber(9);
sp.addNumber(11);
std::cout << sp.shortestSpan() << std::endl;
std::cout << sp.longestSpan() << std::endl;
return 0;
}