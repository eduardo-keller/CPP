/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeller- <ekeller-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 17:41:19 by ekeller-          #+#    #+#             */
/*   Updated: 2026/01/29 14:53:15 by ekeller-         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "easyfind.hpp"
#include <vector>
#include <iostream>
#include <deque>
#include <list>

//contiguos block. fast for access. slow O(n) for insertions/removals.
void testVector(){
    std::vector<int> vec;

    std::cout << "---TEST VECTOR---" << std::endl;
    for (int i = 0; i < 4 ; i++ )
        vec.push_back(i);
    std::cout << "Vector elements: ";
    for (int i = 0; i < 4 ; i++ )
        std::cout << vec[i] << " ";

    std::cout << std::endl;
    std::cout << "Search for value 2 " << std::endl;
    std::cout << "Value found: " << *easyfind(vec, 2) << std::endl;;
    try{
        std::cout << "Search for value 6 " << std::endl;
        easyfind(vec, 6);    
    } catch(const std::exception &e){
        std::cout << "Exception caught: " << e.what() << std::endl;}
}


//semi-contiguos block of memory. allows index based access(which is a type of random access)
//good for insertion at the beggining and end of the deque O(1).
void testDeque(){
    std::deque<int> deq;

    std::cout << "---TEST DEQUE---" << std::endl;
    for (int i = 0; i < 4 ; i++ )
        deq.push_back(i);
    std::cout << "Deque elements: ";
    for (int i = 0; i < 4 ; i++ )
        std::cout << deq[i] << " ";

    std::cout << std::endl;
    std::cout << "Search for value 2 " << std::endl;
    std::cout << "Value found: " << *easyfind(deq, 2) << std::endl;;
    try{
        std::cout << "Search for value 6 " << std::endl;
        easyfind(deq, 6);    
    } catch(const std::exception &e){
        std::cout << "Exception caught: " << e.what() << std::endl;}
}

//linked list. good for cases where many insertions are necessary O(1).
//not good for searching a specific value.  
void testList(){
    std::list<int> lis;

    std::cout << "---TEST LIST---" << std::endl;
    for (int i = 0; i < 4 ; i++ )
        lis.push_back(i);
    std::cout << "List elements: ";
    for (std::list<int>::iterator it = lis.begin(); it != lis.end(); ++it)
        std::cout << *it << " ";

    std::cout << std::endl;
    std::cout << "Search for value 2 " << std::endl;
    std::cout << "Value found: " << *easyfind(lis, 2) << std::endl;;
    try{
        std::cout << "Search for value 6 " << std::endl;
        easyfind(lis, 6);    
    } catch(const std::exception &e){
        std::cout << "Exception caught: " << e.what() << std::endl;}
}


int main(void){
    testVector();
    testDeque();
    testList();
    
}