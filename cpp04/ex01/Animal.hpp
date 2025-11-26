/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeller- <ekeller-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 12:16:56 by ekeller-          #+#    #+#             */
/*   Updated: 2025/11/26 18:27:41 by ekeller-         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>

class Animal{
  protected:
  std::string type;
  
  public:
  Animal();
  Animal(const Animal& obj);
  Animal& operator=(const Animal& obj);
  //must be virtual. im creating an "Animal* a = new Dog()". Im creating a pointer of type animal
  //and assigning a dog object to it. Without virtual, the compiler uses the pointer type (Animal*)
  //to determine which destructor to call at compile-time. It will only call Animal's destructor,
  //ignoring that the actual object is a Dog. This causes memory leaks because Dog and Brain
  //destructors are never called. A virtual destructor enables runtime resolution, allowing
  //the program to check the actual object type (Dog) and call the correct destructor chain.
  virtual ~Animal();

  virtual void makeSound() const;
  const std::string& getType() const;
};

#endif