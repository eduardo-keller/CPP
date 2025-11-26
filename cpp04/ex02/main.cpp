/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeller- <ekeller-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 17:10:12 by ekeller-          #+#    #+#             */
/*   Updated: 2025/11/26 19:05:14 by ekeller-         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Cat.hpp"
#include "WrongCat.hpp"
#include "Dog.hpp"
#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Brain.hpp"
#include <string>
#include <iostream>

int main(){
    // Animal test; //compilation error. cannot instantiate an abstract class.
    std::cout << "\n=== CREATING ARRAY OF ANIMALS (HALF DOGS, HALF CATS) ===\n" << std::endl;
    int size = 2;
    const Animal* a[size];

    for(int i = 0; i < size/2; i++)
    {
        std::cout << "Creating Dog: " << i << std::endl;
        a[i] = new Dog();
    }
    for(int i = size/2; i < size; i++)
    {
        std::cout << "Creating Cat: " << i << std::endl;
        a[i] = new Cat();
    }
    std::cout << "\n=== Check sounds ===\n" << std::endl;
    for(int i = 0; i < size; i++)
    {
        std::cout << a[i]->getType() << " makes the sound: ";
        a[i]->makeSound();
    }
    std::cout << "\n=== Dealocating array memory ===\n" << std::endl;
    for(int i = 0; i < size; i++)
        delete a[i];
    
    
    std::cout << "\n=== CHECK DEEP BRAIN COPIES ===" << std::endl;
    std::cout << "\n=== Check dog copy constructor deep copy ===\n" << std::endl;
    Dog originalDog;
    std::cout << "\n=== Create dog copy ===\n" << std::endl;
    Dog copyDog(originalDog);
    
    std::cout << "\n=== create another dog  to check assignment operator deep copy ===\n" << std::endl;
    Dog assignedDog;

    std::cout << "\nAssigning originalDog to assignedDog:" << std::endl;
	assignedDog = originalDog;

    std::cout << "\n=== Check Cat copy constructor deep copy ===\n" << std::endl;
    Cat originalCat;
    std::cout << "\n=== Create Cat copy ===\n" << std::endl;
    Cat copyCat(originalCat);
    
    std::cout << "\n=== create another Cat  to check assignment operator deep copy ===\n" << std::endl;
    Cat assignedCat;

    std::cout << "\nAssigning originalCat to assignedCat:" << std::endl;
	assignedCat = originalCat;
    
    
    std::cout << "\n=== Calling destructors ===\n" << std::endl;
    
}
