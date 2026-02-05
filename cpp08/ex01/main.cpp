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
#include <ctime>
#include <cstdlib>



int generateRandomInt() {
    static bool seeded = false;
    
    if (!seeded) {
        std::srand(static_cast<unsigned>(std::time(0)));
        seeded = true;
    }
    return (std::rand() % 50000);
}

int main()
{

std::cout << "---RUN SUBJECT TEST---" << std::endl;
Span sp = Span(5);
sp.addNumber(6);
sp.addNumber(3);
sp.addNumber(17);
sp.addNumber(9);
sp.addNumber(11);
std::cout << "Short Span: ";
std::cout << sp.shortestSpan() << std::endl;
std::cout << "Long Span: ";
std::cout << sp.longestSpan() << std::endl;

std::cout << "Try to add value with a full vector should raise exception:" << std::endl;
try {sp.addNumber(15);}
catch(std::exception &e){std::cout << "Exception: " << e.what() << std::endl;}
std::cout << std::endl;

std::cout << "---RUN SINGLE ELEMENT TEST IN VECTOR---" << std::endl;
Span sp_s = Span(1);
sp_s.addNumber(6);
try {sp_s.shortestSpan();}
catch(std::exception &e){std::cout << "Exception short span: " << e.what() << std::endl;}
try {sp_s.longestSpan();}
catch(std::exception &e){std::cout << "Exception long span: " << e.what() << std::endl;}
std::cout << std::endl;

std::cout << "---RUN TEST WITH A 10K RANGE---" << std::endl;
Span big(10000);
std::vector<int> vec;
std::cout << "Generate vector with 10K random numbers" << std::endl;
for(int i = 0; i < 10000; i++){
    vec.push_back(generateRandomInt());
}
std::cout << "Vector size: " << vec.size() << std::endl;
std::cout << "Span size: " << big.get_numbers() << std::endl;
std::cout << "Add vector range to the Span class with addRange()" << std::endl;
big.addRange(vec.begin(), vec.end());
std::cout << "Span size: " << big.get_numbers() << std::endl;

std::cout << "Short Span: ";
std::cout << big.shortestSpan() << std::endl;
std::cout << "Long Span: ";
std::cout << big.longestSpan() << std::endl;
std::cout << "Try to add another range that does not fit the vector:" << std::endl;
try {big.addRange(vec.begin(), vec.end());}
catch(std::exception &e){std::cout << "Exception: " << e.what() << std::endl;}







return 0;
}