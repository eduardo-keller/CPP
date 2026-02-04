/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeller- <ekeller-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 17:21:08 by ekeller-          #+#    #+#             */
/*   Updated: 2026/01/28 12:27:03 by ekeller-         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Array.hpp"
#include <iostream>
#include <string>
#include <cstdlib>

void testArrayInt(void){
    Array<int> empty;
    Array<int> array(5);
    
    for(int i = 0; i < 5; i++)
        array[i] = i+1;
    
    std::cout << "---TEST ARRAY CLASS WITH INT--- " << std::endl;
    std::cout << "Size of empty array: ";
    std::cout << empty.size() << std::endl;
    std::cout << "Size of non empty array: ";
    std::cout << array.size() << std::endl;
    std::cout << "Elements of the array: ";
    for(int i = 0; i < 5; i++)
        std::cout << array[i] << " ";
    std::cout << std::endl;
    std::cout << "Test out of bounds array access at index 5: " << std::endl;
    try{
        std::cout << array[5];}
    catch(const std::out_of_range& e){
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    std::cout << std::endl;
}

void testArrayString(void){
    Array<std::string> empty;
    Array<std::string> array(2);
    
    array[0] = "Hello";
    array[1] = "World!";
    
    std::cout << "---TEST ARRAY CLASS WITH STRING--- " << std::endl;
    std::cout << "Size of empty array: ";
    std::cout << empty.size() << std::endl;
    std::cout << "Size of non empty array: ";
    std::cout << array.size() << std::endl;
    std::cout << "Elements of the array: ";
    for(int i = 0; i < 2; i++)
        std::cout << array[i] << " ";
    std::cout << std::endl;
    std::cout << "Test out of bounds array access at index 2: " << std::endl;
    try{
        std::cout << array[2];}
    catch(const std::out_of_range& e){
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    std::cout << std::endl;
}

void testDeepCopy(){
    Array<int> array(5);
    
    for(int i = 0; i < 5; i++)
        array[i] = i+1;

    std::cout << "---TEST DEEP COPY--- " << std::endl;
    Array<int> copy(array);
    Array<int> copyAssignment;
    copyAssignment = array;
    std::cout << "Elements of the original array: ";
    for(unsigned int i = 0; i < 5; i++)
        std::cout << array[i] << " ";
    std::cout << std::endl;
    std::cout << "Elements of the copied array: ";
    for(unsigned int i = 0; i < 5; i++)
        std::cout << copy[i] << " ";
    std::cout << std::endl;
    std::cout << "Elements of the copy assignment: ";
    for(unsigned int i = 0; i < 5; i++)
        std::cout << copyAssignment[i] << " ";
    std::cout << std::endl;
    std::cout << "Test deep copy by changing original array" << std::endl;
    for(int i = 0; i < 5; i++)
        array[i] = i+5;
    std::cout << "Elements of the altered original array: ";
    for(int i = 0; i < 5; i++)
        std::cout << array[i] << " ";
    std::cout << std::endl;
    std::cout << "Elements of the copied array: ";
    for(int i = 0; i < 5; i++)
        std::cout << copy[i] << " ";
    std::cout << std::endl;
    std::cout << "Elements of the copy assignment: ";
    for(unsigned int i = 0; i < 5; i++)
        std::cout << copyAssignment[i] << " ";
    std::cout << std::endl;
    std::cout << std::endl;
}




int main(){
    testArrayInt();
    testDeepCopy();
    testArrayString();
}
