/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeller- <ekeller-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 17:10:12 by ekeller-          #+#    #+#             */
/*   Updated: 2025/11/26 13:54:05 by ekeller-         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Cat.hpp"
#include "WrongCat.hpp"
#include "Dog.hpp"
#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include <string>
#include <iostream>

int main(){
const Animal* meta = new Animal();
const Animal* j = new Dog();
const Animal* i = new Cat();

std::cout << meta->getType() << " " << std::endl;
std::cout << j->getType() << " " << std::endl;
std::cout << i->getType() << " " << std::endl;
i->makeSound(); 
j->makeSound();
meta->makeSound();
delete meta;
delete j;
delete i;

std::cout << std::endl << "Call wrong animal and cat:" << std::endl << std::endl;


//if the function makesound is not virtual the compiler looks at
//the pointer type (WrongAnimal*), not the actual object type (WrongCat)
const WrongAnimal* w = new WrongCat();
WrongCat cat;
std::cout << w->getType() << " " << std::endl;
std::cout << cat.getType() << " " << std::endl;
w->makeSound();
cat.makeSound();
delete w;
return 0;



}
