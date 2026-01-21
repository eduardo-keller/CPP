/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeller- <ekeller-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 17:11:52 by ekeller-          #+#    #+#             */
/*   Updated: 2026/01/21 16:21:55 by ekeller-         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <string>
#include <iostream>
#include <ctime>
#include <exception>
#include <cstdlib>


Base* generate(void) {
    static bool seeded = false;
    if (!seeded)
    {
        std::srand(std::time(NULL));
        seeded = true;
    }
    
    int rand = std::rand() % 3;
    
    switch (rand) {
        case 0: return new A();
        case 1: return new B();
        default: return new C();
    }
}

//use dynamic_cast to identify the pointer type at 
//run time. if I used static_cast the program would always convert
//the pointer to type A at compile time, and the first if will always be true.
void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
    else
        std::cout << "Unknown\n";
}

//needs to use try/catch because if casting fails,
//it throws an exception. A reference can never be null.
//(void) before dynamic_cast is not strictly necessary
//for clarity, the syntax shows that I only care if it
//throws. 
void identify(Base& p) {
    try {
        (void)dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        return;
    } catch(std::exception&){}
    try {
        (void)dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        return;
    } catch(std::exception&){}
    try {
        (void)dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
        return;
    } catch(std::exception&){}
}

int main(){
    for(int i = 1; i < 6; i++){
        std::cout << "--- Test " << i << " ---" << std::endl;
        Base *ptr;
        ptr = generate();

        std::cout << "Identify by pointer: ";
        identify(ptr);

        std::cout << "Identify by reference: ";
		identify(*ptr);

		delete ptr;
		std::cout << std::endl;
    }
}